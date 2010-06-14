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



#ifndef REGRESSION_H_
#define REGRESSION_H_

#include <vector>
#include <geometry/point.h>
#include <cmath>

/** 
 * Simple functions to perform line fitting 
 *
 * @author Gian Diego Tipaldi
 */


/**
 * Struct defining the parameters of a line;
 *
 * @author Gian Diego Tipaldi
 */

struct LineParameters{
    double rho; /**< The distance of the line from the origin of the axis. */
    double alpha; /**< The angle of the normal vector of the line. */
};

/** 
 * Fits a line in the weighted least squares sense to the points, in cartesian coordinates, with the corresponding weights, 
 * minimizing the weighted perpendicular errors from the points to the line. 
 */

LineParameters computeNormals(const std::vector<Point2D>& points, const std::vector<double>& weights);

/** 
 * Fits a line in the weighted least squares sense to the points, in cartesian coordinates, 
 * minimizing the perpendicular errors from the points to the line. 
 */

LineParameters computeNormals(const std::vector<Point2D>& points);

#endif