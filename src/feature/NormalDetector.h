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



#ifndef NORMALDETECTOR_H_
#define NORMALDETECTOR_H_

#include <feature/InterestPoint.h>
#include <feature/Detector.h>
#include <feature/MultiScaleDetector.h>
#include <utils/Convolution.h>
#include <utils/PeakFinder.h>
#include <utils/Regression.h>

#include <vector>

/**
 * Representation of a general detector based on the normal signal.
 * The class represents a general detector based on the normal signal. It computes the normal signal and define the general interface for detection. 
 * The concrete detectors provides the precise differential invariant.
 *
 * @author Gian Diego Tipaldi
 */

class NormalDetector: public MultiScaleDetector {
    public:
		/** 
		 * Constructor. Constructs and initialize a general detector based on a normal signal. 
		 *
		 * @param peak The peak finder used to detect maxima in the signal.
		 * @param scales The number of different scales to consider.
		 * @param sigma The standard deviation of the smoothing kernel for the initial scale (\f$ t_0 \f$ in the paper). 
		 * @param step The scale increment at every new scale (\f$ t_i \f$ in the paper). The standard deviation of the kernel at scale \f$ s \f$ is \f$ t_0 \cdot (t_i)^s \f$
		 * @param window The window size for the local line fitting.
		 * @param filterType The smoothing kernel used in the detector.
		 */
		NormalDetector(const PeakFinder* peak, unsigned int scales = 5, double sigma = 1.6, double step = 1.4, unsigned int window = 3, SmoothingFilterFamily filterType = BESSEL);
		
		/** Sets the window size for the local line fitting. */
		inline void setWindowSize(unsigned int size)
			{m_windowSize = size;}
			
		/** Gets the window size for the local line fitting. */
		inline unsigned int getWindowSize() const
			{return m_windowSize;}
	
    protected:
		virtual void computeDifferentialBank() = 0;
		virtual void computeSignal(const LaserReading& reading, std::vector<double>& signal, std::vector<unsigned int>& maxRangeMapping) const;
		virtual unsigned int computeInterestPoints(const LaserReading& reading, const std::vector<double>& signal, std::vector<InterestPoint*>& point, 
							std::vector< std::vector<unsigned int> >& indexes, std::vector<unsigned int>& maxRangeMapping) const;
							
		unsigned int m_windowSize; /**< The window size for the local line fitting. */
};

#endif
