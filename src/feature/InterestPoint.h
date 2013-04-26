#ifndef INTERESTPOINT_H_
#define INTERESTPOINT_H_

#include <geometry/point.h>
#include <feature/Descriptor.h>
#include <vector>

/**
 * Representation of an interesting point.
 * The class represents an interesting point. It defines the interface for obtaining the position of the interest point
 * and its descriptor. 
 *
 * @author Gian Diego Tipaldi
 */

class InterestPoint {
    public:
	/** 
	 * Constructor. It creates the interest point providing the position, scale and descriptor.
	 *
	 * @param position The position of the interest point as a point in \f$ \mathcal{SO}(2) \f$.
	 * @param scale The scale at which the interest point was detected.
	 * @param descriptor The descriptor of the interest point.
	 */
	InterestPoint(const OrientedPoint2D& position, double scale, const Descriptor* descriptor = 0);
	
	/** Copy Constructor. */
	InterestPoint(const InterestPoint& point);
	
	/** Assignament operator. */
	InterestPoint& operator=(const InterestPoint& _point);
	
	/** Destructor. */
	virtual ~InterestPoint();
    
	/** Gets the position and orientation of the interest point. */
	inline const OrientedPoint2D& getPosition() const 
	    {return m_position;}

	/** Gets the scale at which the interest point was detected. */
	inline double getScale() const
	    {return m_scale;}
	
	/** Gets the index of the scale at which the interest point is detected. It is used for plotting purposes. */
	inline double getScaleLevel() const
	    {return m_scaleLevel;}
	
	/** Gets the descriptor of the interest point. */
	inline const Descriptor* getDescriptor() const
	    {return m_descriptor;}
	
	/** Gets the points in the support region of the interest point. See the paper for more details. */
	inline const std::vector<Point2D>& getSupport() const
	    {return m_supportPoints;}
	    
	/** Sets the position and orientation of the interest point */
	inline void setPosition(const OrientedPoint2D& _position)
	    {m_position = _position;}
	
	/** Sets the scale at which the interest point was detected. */
	inline void setScale(double _scale)
	    {m_scale = _scale;}
	
	/** Sets the index of the scale at which the interest point is detected. It is used for plotting purposes. */
	inline void setScaleLevel(unsigned int _scale)
	    {m_scaleLevel = _scale;}
	
	/** Sets the descriptor of the interest point. */
	inline void setDescriptor(const Descriptor* _descriptor)
	    {m_descriptor = _descriptor;}
	
	/** Sets the points in the support region of the interest point. See the paper for more details. */
	inline void setSupport(const std::vector<Point2D>& points)
	    {m_supportPoints = points;}
	    
    protected:
	OrientedPoint2D m_position; /**< The position of the interest point as a point in \f$ \mathcal{SO}(2) \f$. */
	std::vector<Point2D> m_supportPoints; /**< The points in the support region of the interest point. See the paper for more details. */
	double m_scale; /**< The scale at which the interest point was detected. */
	unsigned int m_scaleLevel; /**< The index of the scale at which the interest point is detected. It is used for plotting purposes. */
	const Descriptor* m_descriptor; /**< The descriptor of the interest point. */
};

#endif

