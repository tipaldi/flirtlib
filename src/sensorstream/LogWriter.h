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
