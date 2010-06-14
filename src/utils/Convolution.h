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



#ifndef CONVOLUTION_H_
#define CONVOLUTION_H_

#include <vector>
#include <cmath>
#include <boost/math/special_functions/bessel.hpp>
#include <iostream>

/**
 * Simple functions for performing convolution on discrete signals.
 *
 * @author Gian Diego Tipaldi
 */

/**
 * The padding strategy for the convolution operation.
 *
 */
enum ConvolutionPadding{ 
    ZERO, /**< The zero padding strategy. The original signal is augmented with zeros at the borders. */
    SPECULAR, /**< The specular padding strategy. The original signal is replicated in a specular way at the borders. */
    CIRCULAR /**< The circular padding strategy. It implements the circular convolution. */
};

/**
 * The size of the convolution result
 *
 */
enum ConvolutionResult{
    SAME, /**< The convolution result has the same size of the original signal. */
    FULL /**< The convolution result has the full size. */
};


/** 
 * Convolve the kernel over the source, if the size of the source is bigger than the size of the kernel, the opposite otherwise. 
 * The padding is defined according to padding and can be ZERO, SPECULAR or CIRCULAR. The size of the result is defined by resultType 
 * and can be FULL or SAME. The parameter offset define the offset of the kernel with respect to the source.
 *
 * @param source The signal to convolve.
 * @param kernel The convolution kernel. If the kernel is bigger than the source kernel and source are inverted.
 * @param offset The offset of the convolution. It is useful to shifting the signal to the left or right.
 * @param padding The type of padding. See the #ConvolutionPadding enum.
 * @param resultType The size of the convolution result. See the #ConvolutionResult enum.
 */

template<class Numeric>
std::vector<Numeric> convolve1D(const std::vector<Numeric>& source, const std::vector<Numeric>& kernel, int offset = 0, ConvolutionPadding padding = SPECULAR, ConvolutionResult resultType = SAME);

/** 
 * Compute the Bessel kernel for smoothing 
 *
 * @param sigma The standard deviation of the kernel.
 * @param kernelSize The size of the kernel.
 */

template<class Numeric>
std::vector<Numeric> besselKernel1D(Numeric sigma, unsigned int kernelSize);

/** 
 * Compute the Gaussian kernel for smoothing 
 *
 * @param sigma The standard deviation of the kernel.
 * @param kernelSize The size of the kernel.
 */

template<class Numeric>
std::vector<Numeric> gaussianKernel1D(Numeric sigma, unsigned int kernelSize);

/** Print the signal to a stream */
template<class Numeric>
std::ostream& operator<<(std::ostream& out, const std::vector<Numeric>& vector);

// real implementation
#include <utils/Convolution.hpp>

#endif
