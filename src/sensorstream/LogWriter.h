#ifndef LOGWRITER_H_
#define LOGWRITER_H_

#include <sensors/AbstractReading.h>

#include <iostream>
#include <vector>

/** 
 * Representation of an abstract log writer. It defines the interface for writing a log file to a stream.
 *
 *
 * @author Gian Diego Tipaldi
 */
 
class LogWriter{
    public:
	/** Virtual Default destructor */
	virtual ~LogWriter() { }
	
	/** Write a log to an outputstream */
	virtual void writeLog(std::ostream& _stream, const std::vector<AbstractReading*>& _log) const = 0;
};

#endif

