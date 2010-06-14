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

