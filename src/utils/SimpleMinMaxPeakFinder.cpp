#include "SimpleMinMaxPeakFinder.h"

SimpleMinMaxPeakFinder::SimpleMinMaxPeakFinder(double minValue, double minDifference):
    SimplePeakFinder(minValue, minDifference)
{

}

bool SimpleMinMaxPeakFinder::isPeak(const std::vector<double>& signal, unsigned int index) const {
    bool minPeak = signal[index] < -m_minValue && 
		   signal[index] - signal[index - 1] < -m_minDifference &&
		   signal[index] - signal[index + 1] < -m_minDifference;
    return SimplePeakFinder::isPeak(signal,index) || minPeak;
}
