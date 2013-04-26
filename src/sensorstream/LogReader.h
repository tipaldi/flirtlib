#ifndef LOGREADER_H_
#define LOGREADER_H_

#include <sensors/AbstractReading.h>

#include <iostream>
#include <vector>

/** 
 * Representation of an abstract log reader. It defines the interface for reading a log file from a stream.
 *
 * @author Gian Diego Tipaldi
 */
 
class LogReader{
    public:
	/** Virtual Default destructor */
	virtual ~LogReader() { }
	
	/** Read a log from an inputstream */
	virtual void readLog(std::istream& _stream, std::vector<AbstractReading*>& _log) const = 0;
};

#endif

