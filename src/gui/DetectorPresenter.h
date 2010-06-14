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



#ifndef DETECTORPRESENTER_H_
#define DETECTORPRESENTER_H_

#include <feature/Detector.h>
#include <gui/ParameterWidget.h>
#include <QtGui/QWidget>
#include <QtCore/QObject>

#include <iostream>

class DetectorPresenter: public QObject{
    public:
	DetectorPresenter(Detector* detector, ParameterWidget* detectorParameter): 
	    m_detector(detector), 
	    m_detectorParameter(detectorParameter)
	    { }
	
	virtual inline void activate()
	    {if(m_detectorParameter){m_detectorParameter->activate();}}
	virtual inline void deactivate()
	    {if(m_detectorParameter) m_detectorParameter->deactivate();}

	virtual void setDetector(Detector* detector) = 0;

	virtual void setDetectorParameter(ParameterWidget* detectorParameter) = 0;
	
	inline const Detector* getDetector() const
	    {return m_detector;}

	inline const ParameterWidget* getDetectorParameter() const
	    {return m_detectorParameter;}

	inline Detector* getDetector() 
	    {return m_detector;}

	inline ParameterWidget* getDetectorParameter() 
	    {return m_detectorParameter;}


    protected:
	virtual void syncronize() = 0;
	virtual void reconnect() = 0;
	
	Detector* m_detector;
	ParameterWidget* m_detectorParameter;
};

#endif
