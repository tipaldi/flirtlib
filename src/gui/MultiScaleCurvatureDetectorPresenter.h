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



#ifndef MULTISCALECURVATUREDETECTORPRESENTER_H_
#define MULTISCALECURVATUREDETECTORPRESENTER_H_

#include <gui/PeakFinderPresenter.h>
#include <gui/DetectorPresenter.h>
#include <gui/ParameterWidget.h>
#include <feature/CurvatureDetector.h>
#include <QtCore/QVector>
#include <QtCore/QObject>
#include <QtCore/QString>

class MultiScaleCurvatureDetectorPresenter: public DetectorPresenter{
    Q_OBJECT

    public:
	MultiScaleCurvatureDetectorPresenter(CurvatureDetector* detector, ParameterWidget* detectorParameter);
	
	virtual void activate();
	
	virtual void deactivate();
	
	void insertPeakFinder(const QString& name, PeakFinderPresenter* peak);

	void setDetector(Detector* detector);
	
	void setDetectorParameter(ParameterWidget* detectorParameter);
	
    signals:
	void detectorChanged();
	
    public slots:
	void changeParameter(const QString& name);
    
	void changeMaxRange(int check);
	void changeScale(int scale);
	void changeSigma(double sigma);
	void changeSigmaStep(double step);
	void changeDmst(int dmst);
	void changePeakFinder(int peakFinder);	

    protected:
	virtual void syncronize();
	virtual void reconnect();
	
	PeakFinderPresenter* m_currentPeakPresenter;
	int m_currentPeakPresenterIndex;
	QVector< PeakFinderPresenter* > m_peakPresenters;
	QStringList m_peakPresenterNames;
};

#endif
