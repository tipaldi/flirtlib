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



#ifndef FEATURESETMATCHERPRESENTER_H_
#define FEATURESETMATCHERPRESENTER_H_

#include <feature/AbstractFeatureSetMatcher.h>
#include <QtGui/QWidget>
#include <QtCore/QObject>
#include <gui/ParameterWidget.h>

class FeatureSetMatcherPresenter: public QObject{
    Q_OBJECT
    
    public:
	FeatureSetMatcherPresenter(AbstractFeatureSetMatcher* featureSetMatcher, ParameterWidget* featureSetMatcherParameter);

	inline virtual void activate()
	    {if(m_featureSetMatcherParameter) m_featureSetMatcherParameter->activate();}
	inline virtual void deactivate()
	    {if(m_featureSetMatcherParameter) m_featureSetMatcherParameter->deactivate();}

	virtual void setFeatureSetMatcher(AbstractFeatureSetMatcher* featureSetMatcher) = 0;

	virtual void setFeatureSetMatcherParameter(ParameterWidget* peakParameter) = 0;

	    
	inline const AbstractFeatureSetMatcher* getFeatureSetMatcher() const
	    {return m_featureSetMatcher;}
	inline const ParameterWidget* getFeatureSetMatcherParameter() const
	    {return m_featureSetMatcherParameter;}
	
	inline AbstractFeatureSetMatcher* getFeatureSetMatcher() 
	    {return m_featureSetMatcher;}
	inline ParameterWidget* getFeatureSetMatcherParameter() 
	    {return m_featureSetMatcherParameter;}
    
    signals:
	void featureSetMatcherChanged();
	    
    public slots:
	void changeParameter(const QString& name);
	void changeAcceptanceThreshold(double value);

    protected:
	virtual void syncronize();
	virtual void reconnect();

	AbstractFeatureSetMatcher* m_featureSetMatcher;
	ParameterWidget* m_featureSetMatcherParameter;
};

#endif
