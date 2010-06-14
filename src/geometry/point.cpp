#include "point.h"

Point2D::Point2D(): 
    x(0.0),
    y(0.0) 
{ 

}

Point2D::Point2D(double _x, double _y):
    x(_x),
    y(_y) 
{ 

}

OrientedPoint2D::OrientedPoint2D():
    Point2D(0.0,0.0),
    theta(0.0)
{

}

OrientedPoint2D::OrientedPoint2D(double _x, double _y, double _theta):
    Point2D(_x,_y),
    theta(_theta)
{
    
}

OrientedPoint2D OrientedPoint2D::ominus() const
{
    double ctheta = cos(theta), stheta = sin(theta);
    return OrientedPoint2D(-x * ctheta - y * stheta,
			    x * stheta - y * ctheta,
			    -theta);
}
    
OrientedPoint2D OrientedPoint2D::ominus(const OrientedPoint2D& point) const
{
    double ctheta = cos(theta), stheta = sin(theta);
    return OrientedPoint2D( (point.x - x) * ctheta + (point.y - y) * stheta,
			   -(point.x - x) * stheta + (point.y - y) * ctheta,
			     point.theta - theta);

}
    
Point2D OrientedPoint2D::ominus(const Point2D& point) const
{
    double ctheta = cos(theta), stheta = sin(theta);
    return Point2D( (point.x - x) * ctheta + (point.y - y) * stheta,
		   -(point.x - x) * stheta + (point.y - y) * ctheta);

}
    
OrientedPoint2D OrientedPoint2D::oplus(const OrientedPoint2D& point) const
{
    double ctheta = cos(theta), stheta = sin(theta);
    return OrientedPoint2D(x + point.x * ctheta - point.y * stheta,
			   y + point.x * stheta + point.y * ctheta,
			   theta + point.theta);
}

Point2D OrientedPoint2D::oplus(const Point2D& point) const
{
    double ctheta = cos(theta), stheta = sin(theta);
    return Point2D(x + point.x * ctheta - point.y * stheta,
		   y + point.x * stheta + point.y * ctheta);
}


double normAngle(double angle, double base) {
    double pi2 = 2*M_PI;
    double min2pi = base + pi2;
    while(angle>=min2pi) angle -= pi2;
    while(angle<base) angle += pi2;
    return angle;
}

