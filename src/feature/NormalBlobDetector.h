#ifndef NORMALBLOBDETECTOR_H_
#define NORMALBLOBDETECTOR_H_

#include <feature/NormalDetector.h>

/**
 * Representation of the normal blob detector.
 * The class represents the normal blob detector defined in the paper. It extracts blobs (extrema of the second derivative) on the normal signal.
 *
 * @author Gian Diego Tipaldi
 */

class NormalBlobDetector: public NormalDetector {
    public:
		/** 
		 * Constructor. Constructs and initialize the normal blob detector. 
		 *
		 * @param peak The peak finder used to detect maxima in the signal.
		 * @param scales The number of different scales to consider.
		 * @param sigma The standard deviation of the smoothing kernel for the initial scale (\f$ t_0 \f$ in the paper). 
		 * @param step The scale increment at every new scale (\f$ t_i \f$ in the paper). The standard deviation of the kernel at scale \f$ s \f$ is \f$ t_0 \cdot (t_i)^s \f$
		 * @param window The window size for the local line fitting.
		 * @param filterType The smoothing kernel used in the detector.
		 */
		NormalBlobDetector(const PeakFinder* peak, unsigned int scales = 5, double sigma = 1.6, double step = 1.4, unsigned int window = 3, SmoothingFilterFamily filterType = BESSEL);

	/** Default destructor. */
	virtual ~NormalBlobDetector() { }
	
    protected:
		/** Computes the bank for the second derivative at different scales. */
		virtual void computeDifferentialBank();
};

#endif

