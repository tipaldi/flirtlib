#include "SimplePeakFinder.h"

SimplePeakFinder::SimplePeakFinder(double minValue, double minDifference):
    PeakFinder(),
    m_minValue(minValue),
    m_minDifference(minDifference)
{

}

void SimplePeakFinder::findPeaks(const std::vector<double>& signal, std::vector<unsigned int>& indexes) const	{
    indexes.clear();
    for (unsigned int i = 1; i < signal.size() - 1; i++){
	if(isPeak(signal, i)){
	    indexes.push_back(i);
	}
    }
}

bool SimplePeakFinder::isPeak(const std::vector<double>& signal, unsigned int index) const {
    return signal[index] > m_minValue && 
	   signal[index] - signal[index - 1] > m_minDifference &&
	   signal[index] - signal[index + 1] > m_minDifference;
}

void SimplePeakFinder::findPeaks(const std::vector< std::vector<double> >& signal, std::vector< std::vector<unsigned int> >& indexes) const{
    indexes.resize(signal.size());
    for (unsigned int i = 0; i < signal.size(); i++){
	findPeaks(signal[i], indexes[i]);
    }
}

bool SimplePeakFinder::isPeak(const std::vector< std::vector<double> >& signal, unsigned int index1, unsigned int index2) const{
    return isPeak(signal[index1],index2);
}
