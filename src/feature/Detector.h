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



#ifndef DETECTOR_H_
#define DETECTOR_H_

#include <feature/InterestPoint.h>
#include <sensors/LaserReading.h>

/**
 * Representation of an abstract detector.
 * This class represents an abstract detector, defining the interface for detecting interest points in laser readings.
 *
 * @author Gian Diego Tipaldi
 */


class Detector {
    public:
		/** Default destructor. */
		virtual ~Detector() { }

		/** 
		 * Detects the interesting points given the laser reading. 
		 *
		 * @return The number of interest points detected.
		 *
		 * @param reading The laser reading.
		 * @param points The detected interest points.
		 */
		virtual unsigned int detect(const LaserReading& reading, std::vector<InterestPoint*>& points) const = 0;
		
		/** 
		 * Detects the interesting points given the laser reading. It also returns the signals used for the computation.
		 *
		 * @return The number of interest points detected.
		 *
		 * @param reading The laser reading.
		 * @param points The detected interest points.
		 * @param signal The signal used for computing the interest points.
		 * @param signalSmooth The smoothed signal at the different scales.
		 * @param signalDiff The differential operator applied to the signal at the different scales.
		 * @param indexes The indexes of the differential operator maxima at the different scales.
		 */
		virtual unsigned int detect(const LaserReading& reading, std::vector<InterestPoint*>& points,
						std::vector< double >& signal,
						std::vector< std::vector<double> >& signalSmooth,
						std::vector< std::vector<double> >& signalDiff,
						std::vector< std::vector<unsigned int> >& indexes) const = 0;

};

#endif
