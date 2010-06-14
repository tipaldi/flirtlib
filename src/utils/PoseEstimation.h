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



#ifndef POSEESTIMATION_H_
#define POSEESTIMATION_H_

#include <geometry/point.h>
#include <vector>
#include <utility>


/** Function to compute the Euclidean transformation between two set of points. The transformation is computed in closed form minimizing the squared residual reprojection error. */
double compute2DPose(const std::vector< std::pair<Point2D, Point2D> > &correspondences, OrientedPoint2D& transformation);

#endif
