#ifndef SENSORSTREAM_H_
#define SENSORSTREAM_H_

#include <sensors/AbstractReading.h>

/** 
 * \enum SensorStreamOffset The offset from where to seek, values are END or BEGIN.
 *
 * @author Gian Diego Tipaldi
 */
 
enum SensorStreamOffset {
    END,
    BEGIN
};

/** 
 * Representation of an abstract stream of sensor readings.
 * The class represents an abstract sensor stream, providing the interface for obtaining sensor
 * readings, as well as seeking within the stream and checking if the stream is over.
 *
 * @author Gian Diego Tipaldi
 */

class SensorStream {
    public:
	/** Virtual Default destructor */
	virtual ~SensorStream() { }

	/** Get the next reading and advance the stream (const reading) */
	virtual const AbstractReading* next() const = 0;
	
	/** Get the current reading without advancing the stream (const reading) */
	virtual const AbstractReading* current() const = 0;
	
	/** Seek the stream to a given sensor position. Return false if is not possible */
	virtual bool seek(const unsigned int _position = 0, SensorStreamOffset _offset = BEGIN) = 0;
	
	/** Get the current sensor position of the stream. Return 0 if it is not seekable */
	virtual unsigned int tell() const = 0;
	
	/** Check if the stream is seekable */
	virtual inline bool isSeekable() const {return false;}
	
	/** Check if the stream is finished */
	virtual bool end() const = 0 ;
};

#endif

