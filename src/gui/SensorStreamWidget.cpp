#include "SensorStreamWidget.h"
#include "SensorStreamWidget.moc"

SensorStreamWidget::SensorStreamWidget(QWidget * _parent):
    QFrame(_parent),
    m_isSeekable(false),
    m_position(0)
{
    m_layout = new QGridLayout(this);
    m_nextButton = new QPushButton("Next", this);
    m_sensorSlider = new QSlider(this);
    m_sensorBox = new QSpinBox(this);
    m_sensorBox->setMinimum(0);
    
    buildGui();
}

SensorStreamWidget::~SensorStreamWidget(){
    delete m_layout;
	delete m_nextButton;
	delete m_sensorSlider;
	delete m_sensorBox;
}
    
void SensorStreamWidget::seekPosition(int position){
	unsigned int _position(position);
    if(_position == m_position){
		return;
    }
    m_position = _position;
    if(m_isSeekable){
		m_sensorSlider->setValue(_position);
		m_sensorBox->setValue(_position);
    }
    emit newReading(_position);
}

void SensorStreamWidget::nextPosition(){
    if(m_isSeekable){
	seekPosition(m_sensorSlider->value() + m_sensorSlider->singleStep());
    } else {    
	emit newReading();
    }
}

void SensorStreamWidget::seekable(bool _seek, unsigned int _size){
    m_isSeekable = _seek;
    m_sensorSlider->setEnabled(_seek);
    m_sensorSlider->setMaximum(_size);
    m_sensorBox->setEnabled(_seek);
    m_sensorBox->setMaximum(_size);
}

void SensorStreamWidget::streamReady(){
    m_nextButton->setEnabled(true);
}


void SensorStreamWidget::buildGui(){
    m_layout->setSpacing(3);
    m_layout->setMargin(3);
    m_layout->addWidget(m_sensorSlider, 0,0);
    m_layout->addWidget(m_nextButton, 0,1);
    m_layout->addWidget(m_sensorBox, 0,2);
    
    m_sensorSlider->setEnabled(false);
    m_sensorSlider->setOrientation(Qt::Horizontal);
    
    m_nextButton->setEnabled(false);

    connect(m_nextButton, SIGNAL(clicked()), this, SLOT(nextPosition()));
    connect(m_sensorSlider, SIGNAL(valueChanged(int)), this, SLOT(seekPosition(int)));
    connect(m_sensorBox, SIGNAL(valueChanged(int)), this, SLOT(seekPosition(int)));
}
