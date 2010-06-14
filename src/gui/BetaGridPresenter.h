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



#ifndef BETGRIDPRESENTER_H_
#define BETGRIDPRESENTER_H_

#include <gui/DescriptorPresenter.h>
#include <gui/ParameterWidget.h>
#include <feature/BetaGrid.h>
#include <QtGui/QWidget>
#include <QtCore/QObject>

class BetaGridPresenter: public DescriptorPresenter{
    Q_OBJECT
    
    public:
	BetaGridPresenter(BetaGridGenerator* descriptor, ParameterWidget* peakParameter);

	virtual void setDescriptor(DescriptorGenerator* descriptor);
	
	virtual void setDescriptorParameter(ParameterWidget* peakParameter);
	
	void insertDistanceFunction(const QString& name, const HistogramDistance<double>* distanceFunction);
	
    signals:
	void descriptorChanged();
	    
    public slots:
	void changeParameter(const QString& name);
	void changeMinRho(double value);
	void changeMaxRho(double value);
	void changeBinRho(int value);
	void changeBinPhi(int value);
	void changeDistanceFunction(int value);
	
    protected:
	void syncronize();
	void reconnect();
	
	const HistogramDistance<double>* m_currentDistanceFunction;
	int m_currentDistanceFunctionIndex;
	QVector< const HistogramDistance<double>* > m_distanceFunctions;
	QStringList m_distanceFunctionNames;
};

#endif
