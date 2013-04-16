#include "FeatureSetMatcherPresenter.h"
#include "FeatureSetMatcherPresenter.moc"

#include <iostream>

FeatureSetMatcherPresenter::FeatureSetMatcherPresenter(AbstractFeatureSetMatcher* featureSetMatcher, ParameterWidget* featureSetMatcherParameter):
    m_featureSetMatcher(featureSetMatcher),
    m_featureSetMatcherParameter(featureSetMatcherParameter)
{
    m_featureSetMatcherParameter->addDoubleParameter("acceptanceThreshold", "Threshold on the inlier distance", 0.01, 0., 1e17, 3, 0.005);
    syncronize();
    reconnect();
}

void FeatureSetMatcherPresenter::setFeatureSetMatcher(AbstractFeatureSetMatcher* featureSetMatcher){
    m_featureSetMatcher = featureSetMatcher;
    syncronize();
}

void FeatureSetMatcherPresenter::setFeatureSetMatcherParameter(ParameterWidget* featureSetMatcherParameter){
    disconnect(m_featureSetMatcherParameter, 0, this, 0);
    m_featureSetMatcherParameter = featureSetMatcherParameter;
    m_featureSetMatcherParameter->clearParameterMap();
    m_featureSetMatcherParameter->addDoubleParameter("acceptanceThreshold", "Threshold on the inlier distance", 0.01, 0., 1e17, 3, 0.005);
    syncronize();
    reconnect();
}

void FeatureSetMatcherPresenter::changeParameter(const QString& name){
    if(!QString::compare(name, "acceptanceThreshold")){
	double guiValue;
	bool valid = m_featureSetMatcherParameter->getDoubleValue("acceptanceThreshold", guiValue);
	if(valid) {changeAcceptanceThreshold(guiValue);}
    }
}


void FeatureSetMatcherPresenter::changeAcceptanceThreshold(double value){
    AbstractFeatureSetMatcher *featureSetMatcher = (AbstractFeatureSetMatcher *) m_featureSetMatcher;
    double guiValue; 
    m_featureSetMatcherParameter->getDoubleValue(QString("acceptanceThreshold"), guiValue);
//     guiValue = guiValue * guiValue * 5.99;
    double modifiedValue = value * value * 5.99;
    if(featureSetMatcher->getAcceptanceThreshold() != modifiedValue ||  guiValue != value){
	featureSetMatcher->setAcceptanceThreshold(modifiedValue);
	m_featureSetMatcherParameter->setDoubleValue("acceptanceThreshold", value);
	emit featureSetMatcherChanged();
    }
}

void FeatureSetMatcherPresenter::syncronize(){
    AbstractFeatureSetMatcher *featureSetMatcher = (AbstractFeatureSetMatcher *) m_featureSetMatcher;
    double realValue = sqrt(featureSetMatcher->getAcceptanceThreshold() / 5.99);
    m_featureSetMatcherParameter->setDoubleValue("acceptanceThreshold", realValue);
}

void FeatureSetMatcherPresenter::reconnect(){
    connect(m_featureSetMatcherParameter, SIGNAL(parameterChanged(const QString&)), this, SLOT(changeParameter(const QString&)));
}
