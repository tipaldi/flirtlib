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



#ifndef PEAKFINDER_H_
#define PEAKFINDER_H_

#include <vector>

/**
 * Representation of an abstract algorithm for peak finding.
 * The class represents an abstract algorithm for finding peaks in discrete signals.
 *
 * @author Gian Diego Tipaldi
 */

class PeakFinder{
    public:
	/** Default destructor. */
	virtual ~PeakFinder() { }

	/** Finds the indexes of the peaks in a onedimensional signal. */
	virtual void findPeaks(const std::vector<double>& signal, std::vector<unsigned int>& indexes) const = 0;
	
	/** Finds the indexes of the peaks in a bidimensional signal. */
	virtual void findPeaks(const std::vector< std::vector<double> >& signal, std::vector< std::vector<unsigned int> >& indexes) const = 0;
	
	/** Checks if the given index represents a peak in the monodimensional signal */
	virtual bool isPeak(const std::vector<double>& signal, unsigned int index) const = 0;
	
	/** Checks if the given indexes represent a peak in the bidimensional signal */
	virtual bool isPeak(const std::vector< std::vector<double> >& signal, unsigned int index1, unsigned int index2) const = 0;
};

#endif
