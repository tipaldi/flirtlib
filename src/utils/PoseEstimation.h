#ifndef POSEESTIMATION_H_
#define POSEESTIMATION_H_

#include <geometry/point.h>
#include <vector>
#include <utility>

/** Function to compute the Euclidean transformation between two set of points. The transformation is computed in closed form minimizing the squared residual reprojection error. */
double compute2DPose(const std::vector< std::pair<Point2D, Point2D> > &correspondences, OrientedPoint2D& transformation);

#endif

