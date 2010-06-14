/*****************************************************************
 *
 * This file is part of the FLIRTLib project
 *
 * FLIRTLib Copyright (c) 2010 Gian Diego Tipaldi and Kai O. Arras 
 *
 * This software is licensed under the "Creative Commons 
 * License (Attribution-NonCommercial-ShareAlike 3.0)" 
 * and is copyrighted by Gian Diego Tipaldi and Kai O. Arras 
 * 
 * Further information on this license can be found at:
 * http://creativecommons.org/licenses/by-nc-sa/3.0/
 * 
 * FLIRTLib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  
 *
 *****************************************************************/



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
	
	virtual bool isPeak(const std::vector<double>& signal, unsigned int index) const;
};

#endif
