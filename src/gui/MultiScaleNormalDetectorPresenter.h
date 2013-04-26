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

