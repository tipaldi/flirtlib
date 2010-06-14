#include "NormalEdgeDetector.h"


NormalEdgeDetector::NormalEdgeDetector(const PeakFinder* peak, unsigned int scales, double sigma, double step, unsigned int window, SmoothingFilterFamily filterType):
    NormalDetector(peak, scales, sigma, step, window, filterType)
{
    computeDifferentialBank();
}

void NormalEdgeDetector::computeDifferentialBank(){
    m_differentialBank.resize(m_scaleNumber, std::vector<double>(3));
    for(unsigned int i = 0; i < m_differentialBank.size(); i++){
	m_differentialBank[i][0] = -sqrt(m_scales[i])*0.5; 
	m_differentialBank[i][1] = 0; 
	m_differentialBank[i][2] = sqrt(m_scales[i])*0.5;
    }
}

