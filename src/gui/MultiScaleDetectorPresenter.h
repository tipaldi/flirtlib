#ifndef MULTISCALEDETECTORPRESENTER_H_
#define MULTISCALEDETECTORPRESENTER_H_

#include <gui/PeakFinderPresenter.h>
#include <gui/DetectorPresenter.h>
#include <gui/ParameterWidget.h>
#include <feature/MultiScaleDetector.h>
#include <QtCore/QVector>
#include <QtCore/QObject>
#include <QtCore/QString>

class MultiScaleDetectorPresenter: public DetectorPresenter{
    Q_OBJECT

    public:
	MultiScaleDetectorPresenter(MultiScaleDetector* detector, ParameterWidget* detectorParameter);
	
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
	void changeFilter(int filter);
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

