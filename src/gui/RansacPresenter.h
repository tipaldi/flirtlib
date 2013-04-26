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

