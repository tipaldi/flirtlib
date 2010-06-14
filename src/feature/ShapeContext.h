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



#ifndef SHAPECONTEXT_H_
#define SHAPECONTEXT_H_

#include <feature/Descriptor.h>
#include <feature/InterestPoint.h>
#include <sensors/LaserReading.h>
#include <utils/HistogramDistances.h>
#include <vector>

/**
 * Representation of the shape context descriptor. 
 * The class represents the Shape Context descriptor of Belongie et al. It provides the interface
 * to compare different descriptors, as well as to inspect the internal histogram representation.
 * 
 *
 * @author Gian Diego Tipaldi
 */

class ShapeContext: public Descriptor{
    public:
		virtual Descriptor* clone() const;

		/** 
		 * Implements the distance function between two shape context descriptors. 
		 * The actual distance is computed using the histogram distance defined in #m_distanceFunction .
		 * 
		 */
		virtual double distance(const Descriptor* descriptor) const;
	
		/** Returns the shape context in the form of a bidimensional histogram. The first dimension represents the angle and the second dimension the distance. */
		inline const std::vector< std::vector< double > >& getHistogram() const
			{return m_histogram;}
	
		/** Returns the shape context in the form of a bidimensional histogram. The first dimension represents the angle and the second dimension the distance. */
		inline std::vector< std::vector< double > >& getHistogram() 
			{return m_histogram;}
	
		/** Returns the distance function used to compeare two shape contexts. */
		inline const HistogramDistance<double>* getDistanceFunction() const
			{return m_distanceFunction;}
		
		/** Sets the distance function used to compeare two shape contexts. */
		inline void setDistanceFunction(const HistogramDistance<double>* distanceFunction)
			{m_distanceFunction = distanceFunction;}
		
    protected:
		const HistogramDistance<double> *m_distanceFunction; /**< The distance function used to compeare two shape contexts. */ 
		std::vector< std::vector< double > > m_histogram;	/**< The histogram representing the shape context. */
};

/**
 * Representation of the shape context descriptor generator. 
 * The class generates the Shape Context descriptor of Belongie et al. It provides the interface
 * to generate the descriptor from a laser reading and set the descriptor size.
 * 
 *
 * @author Gian Diego Tipaldi
 */

class ShapeContextGenerator: public DescriptorGenerator {
    public:
		/** 
		 * Constructor. It sets the size of the generated shape context and the number of bins.
		 * @param minRho The minimum distance for a point to be included in the descriptor.
		 * @param maxRho The maximum distance for a point to be included in the descriptor.
		 * @param binRho The number of bins in the radial coordinate of the descriptor.
		 * @param binPhi The number of bins in the angular coordinate of the descriptor.
		 */
		ShapeContextGenerator(double minRho, double maxRho, unsigned int binRho, unsigned int binPhi);
		
		/** 
		 * Constructor. It sets the size of the generated shape context and the number of bins.
		 * @param rhoEdges Vector containing the edges of the radial coordinate of the desciptor.
		 * @param phiEdges Vector containing the edges of the angular coordinate of the desciptor.
		 *
		 * \note
		 * A point is in the bin i,j if its radial distance is between rhoEdges[i] and rhoEdges[i + 1] and
		 * its angular distance between phiEdges[j] and phiEdges[j + 1]
		 */
		ShapeContextGenerator(const std::vector<double>& rhoEdges, const std::vector<double>& phiEdges);
		
		virtual Descriptor* describe(const InterestPoint& point, const LaserReading& reading);
		
		virtual Descriptor* describe(const OrientedPoint2D& point, const LaserReading& reading);

		/** Sets the radial and angular edges of the descriptor. 
		 * @param minRho The minimum distance for a point to be included in the descriptor.
		 * @param maxRho The maximum distance for a point to be included in the descriptor.
		 * @param binRho The number of bins in the radial coordinate of the descriptor.
		 * @param binPhi The number of bins in the angular coordinate of the descriptor.
		 */
		void setEdges(double minRho, double maxRho, unsigned int binRho, unsigned int binPhi);
		
		/** Gets the minimum distance for a point to be included in the descriptor. */
		inline double getMinRho() const
			{return m_rhoEdges.front();}
		
		/** Gets the maximum distance for a point to be included in the descriptor. */
		inline double getMaxRho() const
			{return m_rhoEdges.back();}
		
		/** Gets the number of bins in the radial coordinate of the descriptor. */
		inline unsigned int getBinRho() const
			{return m_rhoEdges.size() - 1;}
		
		/** Gets the number of bins in the angular coordinate of the descriptor. */
		inline unsigned int getBinPhi() const
			{return m_phiEdges.size() - 1;}
		
		/** Gets the vector containing the edges of the radial coordinate of the desciptor. */
		inline const std::vector<double>& getRhoEdges() const
			{return m_rhoEdges;}
		
		/** Gets the vector containing the edges of the angular coordinate of the desciptor. */
		inline const std::vector<double>& getPhiEdges() const
			{return m_phiEdges;}
		
		/** Sets the radial and angular edges of the descriptor. 
		 * @param rhoEdges Vector containing the edges of the radial coordinate of the desciptor.
		 * @param phiEdges Vector containing the edges of the angular coordinate of the desciptor.
		 *
		 * \note
		 * A point is in the bin i,j if its radial distance is between rhoEdges[i] and rhoEdges[i + 1] and
		 * its angular distance between phiEdges[j] and phiEdges[j + 1]
		 */
		inline void setEdges(const std::vector<double>& rhoEdges, const std::vector<double>& phiEdges)
			{m_rhoEdges = rhoEdges; m_phiEdges = phiEdges;}
		
		/** Gets the distance function used to compare two descriptors */
		inline const HistogramDistance<double>* getDistanceFunction() const
			{return m_distanceFunction;}
		
		/** Sets the distance function used to compare two descriptors */
		inline void setDistanceFunction(const HistogramDistance<double>* distanceFunction)
			{m_distanceFunction = distanceFunction;}
	
    protected:
		std::vector<double> m_rhoEdges; /**< The vector containing the edges of the radial coordinate of the desciptor. */
		std::vector<double> m_phiEdges; /**< The vector containing the edges of the angular coordinate of the desciptor. */
		const HistogramDistance<double> *m_distanceFunction; /**< The distance function used to compare two descriptors */
};

#endif
