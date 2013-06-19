#ifdef ICOND_H

template<class Particle, class Detector, class Viewer>
ICOND<Particle, Detector, Viewer>::ICOND(int nbParticles, double q, double r) : _Filter<Particle, Viewer>(nbParticles), _q(q), _r(r)
{
	this->_detector = new Detector();
	this->_isDetectorAllocated = true;
}

template<class Particle, class Detector, class Viewer>
ICOND<Particle, Detector, Viewer>::ICOND(Detector* detector, int nbParticles, double q, double r) : _Filter<Particle, Viewer>(nbParticles), _q(q), _r(r)
{
	this->_detector = detector;
	this->_isDetectorAllocated = false;
}

template<class Particle, class Detector, class Viewer>
ICOND<Particle, Detector, Viewer>::~ICOND()
{
	if (this->_isDetectorAllocated) delete this->_detector;
}

template<class Particle, class Detector, class Viewer>
void ICOND<Particle, Detector, Viewer>::init(_Observation& observation)
{
	this->_Ns=this->_nbParticles/1.3;
	this->_Filter<Particle, Viewer>::init(observation);
	this->_detector->init(observation);
	this->_vLambda.resize(this->_nbParticles, 1);

	for (int i=0 ; i<this->_nbParticles ; i++)
	{
		this->_vParticles[i]->sampleFromPrior();
	}
}

template<class Particle, class Detector, class Viewer>
void ICOND<Particle, Detector, Viewer>::update(_Observation& observation)
{
	this->step();
	this->updateWeights(observation);
	this->calcNeff();
	this->computeMMSE();
	if (this->_Neff < this->_Ns) this->resample();
}

template<class Particle, class Detector, class Viewer>
void ICOND<Particle, Detector, Viewer>::update(_Observation& observation, Viewer& viewer)
{
	this->_detector->detect(observation); //update detector
	this->step();
	this->updateWeights(observation);
	viewer.displayWeightedParticles(this->_vParticles, this->_vWeights);
	this->calcNeff();
	this->computeMMSE();
	if (this->_Neff < this->_Ns)
	{
		this->resample();
		viewer.displayResampling(this->_vParticles);
	}
	viewer.displayEstimatedParticle(this->_mmseParticle);
	viewer.updateDisplay();
}

template<class Particle, class Detector, class Viewer>
void ICOND<Particle, Detector, Viewer>::step()
{
	double alpha=0;
	double f, g;
	boost::random::mt19937* pRng = this->_pFilterEnv->getRngSeed();
	boost::random::uniform_01<boost::random::mt19937> rand(*pRng);

	bool isDetection = this->_detector->isDetected();

	int nbPrior=0, nbImp=0, nbDyn=0;

	for (int i=0 ; i<this->_nbParticles ; i++)
	{
		alpha=rand();

		if (alpha < this->_q)
		{
			this->_vParticles[i]->sampleFromPrior();
			this->_vLambda[i]=1;
			nbPrior++;
		}
		else if ((alpha >= this->_q) && (alpha < this->_q+this->_r))//sample from importance
		{
			if (!isDetection) //if no detection, sample from dynamic
			{
				//this->_vParticles[i]->sampleFromPrior();
				//g = this->_vParticles[i]->evaluateFromPrior();
				this->_vParticles[i]->sampleFromDynamic();
				nbDyn++;
			}
			else //else sample from detection
			{
				this->_vParticles[i]->sampleFromDetector(this->_detector->getDetection());
				g = this->_vParticles[i]->evaluateFromPrior();
				f = this->_vWeights[i]*this->_vParticles[i]->evaluateFromDynamic();
				this->_vLambda[i] = f/g;
				nbImp++;
			}

		}
		else
		{
			this->_vParticles[i]->sampleFromDynamic();
			this->_vLambda[i]=1;
			nbDyn++;
		}
	}

	std::cout << "prior : " << nbPrior << " importance : " << nbImp << " dynamics : " << nbDyn << std::endl;
}

template<class Particle, class Detector, class Viewer>
void ICOND<Particle, Detector, Viewer>::updateWeights(_Observation& observation)
{
	this->_weightNorm=0;
	for (int i=0 ; i<this->_nbParticles ; i++)
	{
		this->_vWeights[i] = this->_vLambda[i]*observation.computeLikelihood(*this->_vParticles[i]);
		if (i==0) this->_cdf[i] = this->_vWeights[i];
		else this->_cdf[i] = this->_cdf[i-1] + this->_vWeights[i];

		this->_weightNorm+=this->_vWeights[i];
	}

	for (int i=0 ; i<this->_nbParticles ; i++)
	{
		this->_vWeights[i]/=this->_weightNorm;
		this->_cdf[i]/=this->_weightNorm;
	}
}
#endif
