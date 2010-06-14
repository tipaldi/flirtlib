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



#ifndef SIMPLEPEAKFINDERPRESENTER_H_
#define SIMPLEPEAKFINDERPRESENTER_H_

#include <gui/PeakFinderPresenter.h>
#include <gui/ParameterWidget.h>
#include <utils/SimplePeakFinder.h>
#include <QtGui/QWidget>
#include <QtCore/QObject>

class SimplePeakFinderPresenter: public PeakFinderPresenter{
    Q_OBJECT
    
    public:
	SimplePeakFinderPresenter(SimplePeakFinder* peakFinder, ParameterWidget* peakParameter);

	virtual void setPeakFinder(PeakFinder* peakFinder);
	
	virtual void setPeakFinderParameter(ParameterWidget* peakParameter);
	
    signals:
	void peakFinderChanged();
	    
    public slots:
	void changeParameter(const QString& name);
	void changeMinValue(double value);
	void changeMinDifference(double value);
	
    protected:
	virtual void syncronize();
	virtual void reconnect();
};

#endif
