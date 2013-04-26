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

