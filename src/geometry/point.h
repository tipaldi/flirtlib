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



#ifndef POINT_H_
#define POINT_H_

#include <cmath>
#include <iostream>

/**
 * Representation of a point in \f$ \mathbb{R}^2 \f$ .
 * The class represents 2D points in terms of their position (#x, #y) in in \f$ \mathbb{R}^2 \f$ .
 *
 * @author Gian Diego Tipaldi
 */

struct Point2D {
    /** Default constructor. It sets the point to be in the origin (0,0) */
    Point2D(); 
    /** Constructor. It sets the point to be in (_x, _y) */
    Point2D(double _x, double _y); 
    
    /** Returns the orthogonal vector (rotation of 90 deg) */
    inline Point2D ortho()
	{return Point2D(y, -x);}

    double x; /**< The x coordinate.  */
    double y; /**< The y coordinate. */
};

/**
 * Representation of a point in \f$ \mathcal{SO}(2) \f$ .
 * The class represents points in \f$ \mathcal{SO}(2) \f$ in terms of their position (#x, #y) and their orientation #theta.
 *
 * @author Gian Diego Tipaldi
 */

struct OrientedPoint2D: public Point2D {
    /** Default constructor. It sets the point to be in the origin (0,0,0) */
    OrientedPoint2D(); 
    /** Constructor. It sets the point to be in (_x, _y, _theta) */
    OrientedPoint2D(double _x, double _y, double _theta); 
    
    /** Inverse compound operator \f$ (\ominus this) \f$*/
    OrientedPoint2D ominus() const;
    
    /** Inverse compound operator \f$ (\ominus this) \oplus point \f$ */
    OrientedPoint2D ominus(const OrientedPoint2D& point) const;
    
    /** Inverse compound operator \f$ (\ominus this) \oplus point \f$ */
    Point2D ominus(const Point2D& point) const;
    
    /** Compound operator \f$ this \oplus point \f$ */
    OrientedPoint2D oplus(const OrientedPoint2D& point) const;
    
    /** Compound operator \f$ this \oplus point \f$ */
    Point2D oplus(const Point2D& point) const;
    
    double theta; /**< The orientation of the point. */
};

/** Simple function for convrting degrees into radians */
inline double deg2rad(double _angle) 
    {return _angle/180.0*M_PI;}

/** Simple function for converting radians into degrees */
inline double rad2deg(double _angle) 
    {return _angle/M_PI*180.0;}

/** Simple function for normalizing the angle into the interval \f$(base, 2\pi + base)\f$  */
double normAngle(double angle, double base); 

/** Compute the difference between two points */
inline Point2D operator-(const Point2D& first, const Point2D& last)
    {return Point2D(first.x - last.x, first.y - last.y);}

/** Compute the sum between two points */
inline Point2D operator+(const Point2D& first, const Point2D& last)
    {return Point2D(first.x + last.x, first.y + last.y);}
    
/** Compute the analitical difference between two oriented points */
inline OrientedPoint2D operator-(const OrientedPoint2D& first, const OrientedPoint2D& last)
    {return OrientedPoint2D(first.x - last.x, first.y - last.y, normAngle(first.theta - last.theta, -M_PI));}

/** Compute the analitical sum between two oriented points */
inline OrientedPoint2D operator+(const OrientedPoint2D& first, const OrientedPoint2D& last)
    {return OrientedPoint2D(first.x + last.x, first.y + last.y, normAngle(first.theta + last.theta, -M_PI));}
    
/** Compute the product of a point with a scalar */
inline Point2D operator*(const Point2D& first, const double last)
    {return Point2D(first.x * last, first.y * last);}

/** Compute the product of a point with a scalar */
inline Point2D operator*(const double last, const Point2D& first)
    {return Point2D(first.x * last, first.y * last);}
    
/** Compute the dot product of two points*/
inline double operator*(const Point2D& first, const Point2D& last)
    {return first.x * last.x + first.y * last.y;}

/** Print the Point2D */
inline std::ostream& operator << (std::ostream& out, const Point2D& point)
    {out << "(" << point.x << ", " << point.y << ")"; return out;}

/** Print the OrientedPoint2D */
inline std::ostream& operator << (std::ostream& out, const OrientedPoint2D& point)
    {out << "(" << point.x << ", " << point.y << ", " << point.theta << ")"; return out;}

#endif

