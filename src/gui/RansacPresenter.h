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



#ifndef RANSACPRESENTER_H_
#define RANSACPRESENTER_H_

#include <gui/FeatureSetMatcherPresenter.h>
#include <gui/ParameterWidget.h>
#include <feature/RansacFeatureSetMatcher.h>
#include <QtGui/QWidget>
#include <QtCore/QObject>

class RansacPresenter: public FeatureSetMatcherPresenter{
    Q_OBJECT
    
    public:
	RansacPresenter(RansacFeatureSetMatcher* featureSetMatcher, ParameterWidget* featureSetMatcherParameter);

	virtual void setFeatureSetMatcher(AbstractFeatureSetMatcher* featureSetMatcher);
	
	virtual void setFeatureSetMatcherParameter(ParameterWidget* peakParameter);
	
/*    signals:
	void featureSetMatcherChanged();*/
	    
    public slots:
	void changeParameter(const QString& name);
	void changeSuccessProbability(double value);
	void changeInlierProbability(double value);
	void changeDistanceThreshold(double value);
	void changeAdaptive(int value);
	
    protected:
	virtual void syncronize();
	virtual void reconnect();
};

#endif
