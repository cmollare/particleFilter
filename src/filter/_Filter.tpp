#ifdef FILTER_H

template <class Particle, class Viewer>
_Filter<Particle, Viewer>::_Filter(int nbParticles) : _nbParticles(nbParticles)
{
	_pFilterEnv = new FilterEnv;

	//Particles allocation
	this->_vParticles.resize(this->_nbParticles, NULL);
	for (int i=0 ; i<this->_nbParticles ; i++) this->_vParticles[i] = new Particle(_pFilterEnv);

	this->_mmseParticle = new Particle(_pFilterEnv);
}

template <class Particle, class Viewer>
_Filter<Particle, Viewer>::~_Filter()
{
	for (int i=0 ; i<this->_nbParticles ; i++)
	{
		if (this->_vParticles[i]) delete this->_vParticles[i];
	}
	if (this->_mmseParticle) delete this->_mmseParticle;

	delete _pFilterEnv;
}

template <class Particle, class Viewer>
void _Filter<Particle, Viewer>::init()
{

	//Initiate weights
	this->_vWeights.resize(this->_nbParticles, 1./this->_nbParticles);
	this->_cdf.resize(this->_nbParticles, 0); //weight cdf

	for (int i=0 ; i<this->_nbParticles ; i++) this->_vParticles[i]->sampleFromPrior();
}

template <class Particle, class Viewer>
void _Filter<Particle, Viewer>::updateWeights(_Observation& observation)
{
	this->_weightNorm=0;
	for (int i=0 ; i<this->_nbParticles ; i++)
	{
		this->_vWeights[i] = this->_vWeights[i]*observation.computeLikelihood(*this->_vParticles[i]);
		if (i==0) this->_cdf[i] = this->_vWeights[i];
		else this->_cdf[i] = this->_cdf[i-1] + this->_vWeights[i];

		this->_weightNorm+=this->_vWeights[i];
	}

	for (int i=0 ; i<_nbParticles ; i++)
	{
		this->_vWeights[i]/=this->_weightNorm;
		this->_cdf[i]/=this->_weightNorm;
	}
}

template <class Particle, class Viewer>
void _Filter<Particle, Viewer>::resample()
{
	double invNbPart = 1./this->_nbParticles;
	boost::random::uniform_real_distribution<double> unif(0, invNbPart);
	double u = unif(_rng);

	int i=0;
	for (int j=0 ; j<this->_nbParticles ; j++)
	{
		while (u>this->_cdf[i])
		{
			i++;
			if (i>=this->_nbParticles)
			{
				i=this->_nbParticles-1;
				break;
			}
		}

		*this->_vParticles[j] = *this->_vParticles[i];
		this->_vWeights[j]=invNbPart;
		u=u+invNbPart;
	}

}

template <class Particle, class Viewer>
void _Filter<Particle, Viewer>::computeMMSE()
{

	int stateVecSize = _vParticles[0]->getStateVector().size();
	std::vector<double> tempoStateVector(stateVecSize, 0);

	for (int i=0 ; i<_nbParticles ; i++)
	{
		for (int j=0 ; j<stateVecSize ; j++)
		{
			tempoStateVector[j]+= this->_vWeights[i]*_vParticles[i]->getStateVector()[j];
		}
	}
	_mmseParticle->setStateVector(tempoStateVector);
}

#endif
