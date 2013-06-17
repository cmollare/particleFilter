#ifdef SIR_H

template <class Particle, class Viewer>
SIR<Particle, Viewer>::SIR(int nbParticles) : _Filter<Particle, Viewer>(nbParticles)
{
}

template <class Particle, class Viewer>
SIR<Particle, Viewer>::~SIR()
{
}

template <class Particle, class Viewer>
void SIR<Particle, Viewer>::init()
{
	_Filter<Particle, Viewer>::init();
	for (int i=0 ; i<this->_nbParticles ; i++)
	{
		this->_vParticles[i]->sampleFromPrior();
	}
}

template <class Particle, class Viewer>
void SIR<Particle, Viewer>::update(_Observation& observation)
{
	this->step();
	this->updateWeights(observation);
	this->computeMMSE();
	this->resample();
}

template <class Particle, class Viewer>
void SIR<Particle, Viewer>::update(_Observation& observation, Viewer& viewer)
{
	this->step();
	this->updateWeights(observation);
	viewer.displayWeightedParticles(this->_vParticles, this->_vWeights);
	this->computeMMSE();
	this->resample();
	viewer.displayResampling(this->_vParticles);
	viewer.displayEstimatedParticle(this->_mmseParticle);
	viewer.updateDisplay();
}

template <class Particle, class Viewer>
void SIR<Particle, Viewer>::step()
{
	for (int i=0 ; i<this->_nbParticles ; i++)
	{
		this->_vParticles[i]->sampleFromDynamic();
	}
}

#endif
