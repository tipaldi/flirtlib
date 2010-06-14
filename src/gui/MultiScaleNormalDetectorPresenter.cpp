#include "MultiScaleNormalDetectorPresenter.h"
#include "MultiScaleNormalDetectorPresenter.moc"

#include <iostream>

MultiScaleNormalDetectorPresenter::MultiScaleNormalDetectorPresenter(NormalDetector* detector, ParameterWidget* detectorParameter):
    MultiScaleDetectorPresenter(detector, detectorParameter)
{
    m_detectorParameter->addIntParameter("windowSize", "Size of the normal window", 3, 3, 11, 2);

    syncronize();
    reconnect();
}

void MultiScaleNormalDetectorPresenter::setDetectorParameter(ParameterWidget* detectorParameter){
    disconnect(m_detectorParameter, 0, this, 0);
    MultiScaleDetectorPresenter::setDetectorParameter(detectorParameter);
    m_detectorParameter->addIntParameter("windowSize", "Size of the normal window", 3, 3, 11, 2);
    m_detectorParameter = detectorParameter;
    syncronize();
    reconnect();
}



void MultiScaleNormalDetectorPresenter::changeParameter(const QString& name){
    if(!QString::compare(name, "windowSize")){
	int guiValue;
	bool valid = m_detectorParameter->getIntValue("windowSize", guiValue);
	if(valid) {changeWindowSize(guiValue);}
    } else {
	MultiScaleDetectorPresenter::changeParameter(name);
    }
}

void MultiScaleNormalDetectorPresenter::changeWindowSize(int size){
    NormalDetector *detector = dynamic_cast<NormalDetector *>(m_detector);
    if(!detector || !m_detectorParameter) return;
    if((int)detector->getWindowSize() != size || m_detectorParameter->getIntValue("windowSize") != size){
	detector->setWindowSize(size);
	m_detectorParameter->setIntValue("windowSize", detector->getWindowSize());
	emit detectorChanged();
    }
}

void MultiScaleNormalDetectorPresenter::syncronize(){
    NormalDetector *detector = dynamic_cast<NormalDetector *>(m_detector);
    if(detector && m_detectorParameter){
	m_detectorParameter->setIntValue("windowSize", detector->getWindowSize());
    }
    MultiScaleDetectorPresenter::syncronize();
}

void MultiScaleNormalDetectorPresenter::reconnect(){
    disconnect(m_detectorParameter, 0, this, 0);
    connect(m_detectorParameter, SIGNAL(parameterChanged(const QString&)), this, SLOT(changeParameter(const QString&)));
}
