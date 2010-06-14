#include "InterestPoint.h"

InterestPoint::InterestPoint(const OrientedPoint2D& _position, double _scale, const Descriptor* _descriptor):
    m_position(_position),
    m_scale(_scale),
    m_scaleLevel(0),
    m_descriptor(_descriptor)
{

}

InterestPoint::InterestPoint(const InterestPoint& _point):
    m_position(_point.getPosition()),
    m_scale(_point.getScale()),
    m_scaleLevel(_point.getScaleLevel())
{
    if(_point.getDescriptor()) 
	m_descriptor = _point.getDescriptor()->clone();
    else
	m_descriptor = 0;
}

InterestPoint& InterestPoint::operator=(const InterestPoint& _point){
    m_position = _point.getPosition();
    m_scale = _point.getScale();
    m_scaleLevel = _point.getScaleLevel();
    delete m_descriptor;
    m_descriptor = _point.getDescriptor()->clone();
    return *this;
}

InterestPoint::~InterestPoint(){
    delete m_descriptor;
}
