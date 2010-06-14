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



#ifndef MULTISCALENORMALDETECTORPRESENTER_H_
#define MULTISCALENORMALDETECTORPRESENTER_H_

#include <gui/PeakFinderPresenter.h>
#include <gui/MultiScaleDetectorPresenter.h>
#include <gui/ParameterWidget.h>
#include <feature/NormalDetector.h>
#include <QtCore/QVector>
#include <QtCore/QObject>
#include <QtCore/QString>

class MultiScaleNormalDetectorPresenter: public MultiScaleDetectorPresenter{
    Q_OBJECT

    public:
	MultiScaleNormalDetectorPresenter(NormalDetector* detector, ParameterWidget* detectorParameter);
	
	void setDetectorParameter(ParameterWidget* detectorParameter);

    public slots:
	void changeParameter(const QString& name);
	
	void changeWindowSize(int size);

    protected:
	virtual void syncronize();
	virtual void reconnect();
};

#endif
