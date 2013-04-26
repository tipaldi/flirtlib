#ifndef DETECTORCHOOSERPRESENTER_H_
#define DETECTORCHOOSERPRESENTER_H_

#include <gui/DetectorPresenter.h>
#include <gui/ParameterWidget.h>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QGridLayout>
#include <QtCore/QVector>
#include <QtCore/QObject>
#include <QtCore/QString>

// class DetectorChooserWidget: public QWidget{
//     Q_OBJECT
//     
//     public:
// 	DetectorChooserWidget(QWidget * parent = 0);
//     
// 	inline int getDetector() const
// 	    {return m_detector.currentIndex();}
// 	inline void insertDetector(const QString& name)
// 	    {m_detector.addItem(name);}
// 	    
// 	void resetDetector();
// 	
//     signals:
// 	void detectorChanged(int detector);
// 	
//     public slots:
// 	void changeDetector(int detector);
// 	
//     protected:
// 	void buildGui();
// 	
// 	QComboBox m_detector;
// 	QLabel m_detectorLabel;
// 	QGridLayout m_layout;
// 
// };

class DetectorChooserPresenter: public QObject{
    Q_OBJECT

    public:
	DetectorChooserPresenter(ParameterWidget* chooser);
	
	void insertDetector(const QString& name, DetectorPresenter* detector);

	void setChooser(ParameterWidget* chooser);
	
	inline const ParameterWidget* getChooserParameter() const
	    {return m_chooser;}
	
	inline const DetectorPresenter* getCurrentDetectorPresenter() const
	    {return m_currentDetectorPresenter;}
	
	inline const Detector* getCurrentDetector() const
	    {return m_currentDetectorPresenter->getDetector();}
	
	inline ParameterWidget* getChooserParameter() 
	    {return m_chooser;}
	
	inline DetectorPresenter* getCurrentDetectorPresenter() 
	    {return m_currentDetectorPresenter;}
	
	inline Detector* getCurrentDetector() 
	    {return m_currentDetectorPresenter->getDetector();}
		
    signals:
	void detectorChanged();
	
    public slots:
	void changeDetector(int detector);	
	void changeParameter(const QString& name);	

    protected:
	void syncronize();
	void reconnect();
	ParameterWidget* m_chooser;
	DetectorPresenter* m_currentDetectorPresenter;
	int m_currentDetectorPresenterIndex;
	QVector< DetectorPresenter* > m_detectorPresenters;
	QStringList m_detectorPresenterNames;
};

#endif

