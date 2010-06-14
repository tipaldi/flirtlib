#include "SimplePeakFinderPresenter.h"
#include "SimplePeakFinderPresenter.moc"

#include <iostream>

SimplePeakFinderPresenter::SimplePeakFinderPresenter(SimplePeakFinder* peakFinder, ParameterWidget* peakParameter):
    PeakFinderPresenter(peakFinder, peakParameter)
{
    m_peakFinderParameter->addDoubleParameter("minValue", "Minimum value", 0., 0.);
    m_peakFinderParameter->addDoubleParameter("minDifference", "Minimum difference", 0., 0., 10e16, 4, 0.01);
    syncronize();
    reconnect();
}

void SimplePeakFinderPresenter::setPeakFinder(PeakFinder* peakFinder){
    m_peakFinder = peakFinder;
    syncronize();
}

void SimplePeakFinderPresenter::setPeakFinderParameter(ParameterWidget* peakParameter){
    disconnect(m_peakFinderParameter, 0, this, 0);
    m_peakFinderParameter = peakParameter;
    m_peakFinderParameter->clearParameterMap();
    m_peakFinderParameter->addDoubleParameter("minValue", "Minimum value", 0., 0.);
    m_peakFinderParameter->addDoubleParameter("minDifference", "Minimum difference", 0., 0., 10e16, 4, 0.01);
    syncronize();
    reconnect();
}

void SimplePeakFinderPresenter::changeParameter(const QString& name){
    if(!QString::compare(name, "minValue")){
	double guiValue;
	bool valid = m_peakFinderParameter->getDoubleValue("minValue", guiValue);
	if(valid) {changeMinValue(guiValue);}
    } else if(!QString::compare(name, "minDifference")){
	double guiValue;
	bool valid = m_peakFinderParameter->getDoubleValue("minDifference", guiValue);
	if(valid) {changeMinDifference(guiValue);}
    }
}


void SimplePeakFinderPresenter::changeMinValue(double value){
    SimplePeakFinder *peakFinder = (SimplePeakFinder *) m_peakFinder;
    double guiValue; 
    m_peakFinderParameter->getDoubleValue(QString("minValue"), guiValue);
    if(peakFinder->getMinValue() != value ||  guiValue != value){
	peakFinder->setMinValue(value);
	m_peakFinderParameter->setDoubleValue("minValue", peakFinder->getMinValue());
	emit peakFinderChanged();
    }
}

void SimplePeakFinderPresenter::changeMinDifference(double value){
    SimplePeakFinder *peakFinder = (SimplePeakFinder *) m_peakFinder;
    double guiValue; 
    m_peakFinderParameter->getDoubleValue("minDifference", guiValue);
    if(peakFinder->getMinDifference() != value || guiValue != value){
	peakFinder->setMinDifference(value);
	m_peakFinderParameter->setDoubleValue("minDifference", peakFinder->getMinDifference());
	emit peakFinderChanged();
    }
}

void SimplePeakFinderPresenter::syncronize(){
    SimplePeakFinder *peakFinder = (SimplePeakFinder *) m_peakFinder;
    m_peakFinderParameter->setDoubleValue("minValue", peakFinder->getMinValue());
    m_peakFinderParameter->setDoubleValue("minDifference", peakFinder->getMinDifference());
}

void SimplePeakFinderPresenter::reconnect(){
    connect(m_peakFinderParameter, SIGNAL(parameterChanged(const QString&)), this, SLOT(changeParameter(const QString&)));
}
