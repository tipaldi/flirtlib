#ifndef SIMPLEMINMAXPEAKFINDER_H_
#define SIMPLEMINMAXPEAKFINDER_H_

#include <utils/SimplePeakFinder.h>
#include <vector>

/**
 * Representation of a simple algorithm for peak finding.
 * The class represents a simple algorithm for finding peaks in discrete signals.
 * The algorithm finds both positive and negative peaks.
 *
 * @author Gian Diego Tipaldi
 */

class SimpleMinMaxPeakFinder: public SimplePeakFinder{
    public:
	/**
	 * Constructor. Creates and initializes the peak finder.
	 *
	 * @param minValue The minimum value for a peak to be considerated valid. The negative value is used for the negative peak. 
	 * @param minDifference The minimum difference a peak should have with respect to its immediate neighbours. The negative value is used for the negative peak.
	 */
	SimpleMinMaxPeakFinder(double minValue = 0.0, double minDifference = 0.0);
	
	/** Default destructor. */
	virtual ~SimpleMinMaxPeakFinder() { }

	virtual bool isPeak(const std::vector<double>& signal, unsigned int index) const;
};

#endif

