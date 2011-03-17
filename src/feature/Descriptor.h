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



#ifndef DESCRIPTOR_H_
#define DESCRIPTOR_H_

class InterestPoint;
class LaserReading;
class OrientedPoint2D;

/**
 * Representation of an abstract descriptor.
 * The class represents an abstract descriptor, defining the interface for comparing two descriptors.
 *
 * @author Gian Diego Tipaldi
 */

class Descriptor {
	public:
		/** Clone function for prototyping. It implements the Prototype pattern. */
		virtual Descriptor* clone() const = 0;

		/** Default destructor. */
		virtual ~Descriptor() { }
		
		/** Abstract interface for computing the distance between two descriptors. The implementation of the actual distance is left to the inherited classes. */
		virtual double distance(const Descriptor* descriptor) const = 0;
};

/**
 * Representation of an abstract descriptor generator.
 * The class represents an abstract descriptor generator, defining the interface for generating the description of an interest point.
 *
 * @author Gian Diego Tipaldi
 */

class DescriptorGenerator{
    public:

	/** Default destructor. */
	virtual ~DescriptorGenerator() { }

		/** Abstract interface for generating a descriptors given an interest point and a laser reading. */
		virtual Descriptor* describe(const InterestPoint& _point, const LaserReading& reading) = 0;
		
		/** Abstract interface for generating a descriptors given a general point in \f$ \mathcal{SO}(2) \f$  and a laser reading. */
		virtual Descriptor* describe(const OrientedPoint2D& _point, const LaserReading& reading) = 0;
};

#endif
