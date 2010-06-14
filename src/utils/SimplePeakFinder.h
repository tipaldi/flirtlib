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



#ifndef SIMPLEPEAKFINDER_H_
#define SIMPLEPEAKFINDER_H_

#include <utils/PeakFinder.h>
#include <vector>

/**
 * Representation of a simple algorithm for peak finding.
 * The class represents a simple algorithm for finding peaks in discrete signals.
 *
 * @author Gian Diego Tipaldi
 */

class SimplePeakFinder: public PeakFinder{
    public:
	/**
	 * Constructor. Creates and initializes the peak finder.
	 *
	 * @param minValue The minimum value for a peak to be considerated valid. 
	 * @param minDifference The minimum difference a peak should have with respect to its immediate neighbours.
	 */
	SimplePeakFinder(double minValue = 0.0, double minDifference = 0.0);
	
	virtual void findPeaks(const std::vector<double>& signal, std::vector<unsigned int>& indexes) const;
	
	virtual void findPeaks(const std::vector< std::vector<double> >& signal, std::vector< std::vector<unsigned int> >& indexes) const;
	
	virtual bool isPeak(const std::vector<double>& signal, unsigned int index) const;
	
	virtual bool isPeak(const std::vector< std::vector<double> >& signal, unsigned int index1, unsigned int index2) const;
	
	/** Gets the minimum value for a peak to be considerated valid. */
	inline double getMinValue() const
	    {return m_minValue;}
	
	/** Gets the minimum difference a peak should have with respect to its immediate neighbours. */
	inline double getMinDifference() const
	    {return m_minDifference;}
	
	/** Sets the minimum value for a peak to be considerated valid. */
	inline void setMinValue(double value)
	    {m_minValue = value;}
	
	/** Sets the minimum difference a peak should have with respect to its immediate neighbours. */
	inline void setMinDifference(double value)
	    {m_minDifference = value;}
    protected:
	double m_minValue; /**< The minimum value for a peak to be considerated valid.  */
	double m_minDifference; /**< The minimum difference a peak should have with respect to its immediate neighbours. */
};

#endif
