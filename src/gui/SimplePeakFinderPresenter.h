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

