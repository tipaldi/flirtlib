#ifndef SENSORSTREAMWIDGET_H_
#define SENSORSTREAMWIDGET_H_

#include <sensorstream/SensorStream.h>

#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QFrame>
#include <QtGui/QSpinBox>

class SensorStreamWidget: public QFrame{
    Q_OBJECT
    
    public:
	SensorStreamWidget(QWidget * _parent = 0);
	virtual ~SensorStreamWidget();
    
    signals:
	void newReading();
	void newReading(int _position);
	
    public slots:
	void seekPosition(int _position);
	void nextPosition();
	void seekable(bool seek, unsigned int _size = 0);
	void streamReady();

    protected:
	void buildGui();
    
	bool m_isSeekable;
	unsigned int m_position;
	QGridLayout *m_layout;
	QPushButton *m_nextButton;
	QSlider *m_sensorSlider;
	QSpinBox *m_sensorBox;
};

#endif

