#include "MultiScaleDetectorPlotWidget.h"

#include "MultiScaleDetectorPlotWidget.moc"

#include <iostream>

MultiScaleDetectorPlotWidget::MultiScaleDetectorPlotWidget(QWidget* parent, unsigned int _scales): 
    QWidget(parent),
    m_scales(_scales)
{ 
    m_plotLayout = new QGridLayout(this);
    m_smooth = new QwtPlot(QwtText("Smoothed signal"), this);
    m_derivative = new QwtPlot(QwtText("Differential operator"), this);
    m_smoothZoomer = new QwtPlotZoomer(m_smooth->canvas());
    m_diffZoomer = new QwtPlotZoomer(m_derivative->canvas());
    
    buildGui();
    initCurves();
    
}

MultiScaleDetectorPlotWidget::~MultiScaleDetectorPlotWidget() { 
    delete m_plotLayout;
    delete m_smooth;
    delete m_derivative;
    delete m_smoothZoomer;
    delete m_diffZoomer;
    for(unsigned int i = 0; i < m_scales; i ++){
	delete m_smoothCurve[i];
	delete m_smoothMarker[i];
	delete m_diffCurve[i];
	delete m_diffMarker[i];
    }
}

void MultiScaleDetectorPlotWidget::buildGui(){
    m_plotLayout->setSpacing(3);
    m_plotLayout->setMargin(3);
    m_plotLayout->addWidget(m_smooth,0,0);
    m_plotLayout->addWidget(m_derivative,0,1);
    setMaximumHeight(256);
    setMinimumHeight(256);

    m_smoothZoomer->setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    m_smoothZoomer->setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
    m_diffZoomer->setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    m_diffZoomer->setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);
    
    m_smooth->plotLayout()->setAlignCanvasToScales(true);
    m_derivative->plotLayout()->setAlignCanvasToScales(true);

}

void MultiScaleDetectorPlotWidget::initCurves(){
    for(int i = 0; i < m_smoothCurve.size(); i ++){
	delete m_smoothCurve[i];
	delete m_smoothMarker[i];
	delete m_diffCurve[i];
	delete m_diffMarker[i];
    }
    m_smoothCurve.resize(m_scales); 
    m_smoothMarker.resize(m_scales); 
    m_diffCurve.resize(m_scales); 
    m_diffMarker.resize(m_scales); 
    m_colors.resize(m_scales);
    QColor colors[12] = {Qt::red, Qt::green, Qt::blue, Qt::cyan, Qt::yellow, Qt::magenta,
			 Qt::darkRed, Qt::darkGreen, Qt::darkBlue, Qt::darkCyan, Qt::darkYellow, Qt::darkMagenta};
    for(unsigned int i = 0; i < m_scales; i ++){
	m_colors[i] = colors[i%12];
	QwtSymbol symbol(QwtSymbol::Ellipse, QBrush(), QPen(m_colors[i]),QSize(10,10));
	m_smoothCurve[i] = new QwtPlotCurve();
	m_smoothCurve[i]->setStyle(QwtPlotCurve::Lines);
	m_smoothCurve[i]->setPen(QPen(m_colors[i]));
	m_smoothCurve[i]->attach(m_smooth);
	m_smoothMarker[i] = new QwtPlotCurve();
	m_smoothMarker[i]->setStyle(QwtPlotCurve::NoCurve);
	m_smoothMarker[i]->setSymbol(symbol);
	m_smoothMarker[i]->attach(m_smooth);
	m_diffCurve[i] = new QwtPlotCurve();
	m_diffCurve[i]->setStyle(QwtPlotCurve::Lines);
	m_diffCurve[i]->setPen(QPen(m_colors[i]));
	m_diffCurve[i]->attach(m_derivative);
	m_diffMarker[i] = new QwtPlotCurve();
	m_diffMarker[i]->setStyle(QwtPlotCurve::NoCurve);
	m_diffMarker[i]->setSymbol(symbol);
	m_diffMarker[i]->attach(m_derivative);
   }
}

void MultiScaleDetectorPlotWidget::setSmoothData(QVector<double>& _dataX, QVector<double>& _dataY, unsigned int _scale){
    setData(m_smoothCurve, _dataX, _dataY, _scale);
}

void MultiScaleDetectorPlotWidget::setSmoothData(QVector< QVector<double> >& _dataX, QVector< QVector<double> >& _dataY){
    setData(m_smoothCurve, _dataX, _dataY);
}

void MultiScaleDetectorPlotWidget::setDifferentialData(QVector<double>& _dataX, QVector<double>& _dataY, unsigned int _scale){
    setData(m_diffCurve, _dataX, _dataY, _scale);
}

void MultiScaleDetectorPlotWidget::setDifferentialData(QVector< QVector<double> >& _dataX, QVector< QVector<double> >& _dataY){
    setData(m_diffCurve, _dataX, _dataY);
}

void MultiScaleDetectorPlotWidget::setSmoothMarker(QVector<double>& _dataX, QVector<double>& _dataY, unsigned int _scale){
    setData(m_smoothMarker, _dataX, _dataY, _scale);
}

void MultiScaleDetectorPlotWidget::setSmoothMarker(QVector< QVector<double> >& _dataX, QVector< QVector<double> >& _dataY){
    setData(m_smoothMarker, _dataX, _dataY);
}

void MultiScaleDetectorPlotWidget::setDifferentialMarker(QVector<double>& _dataX, QVector<double>& _dataY, unsigned int _scale){
    setData(m_diffMarker, _dataX, _dataY, _scale);
}

void MultiScaleDetectorPlotWidget::setDifferentialMarker(QVector< QVector<double> >& _dataX, QVector< QVector<double> >& _dataY){
    setData(m_diffMarker, _dataX, _dataY);
}

void MultiScaleDetectorPlotWidget::setData(QVector<QwtPlotCurve *>& _curve, QVector<double>& _dataX, QVector<double>& _dataY, unsigned int _scale){
    if(_scale < m_scales){
	_curve[_scale]->setData(_dataX, _dataY);
    }
}

void MultiScaleDetectorPlotWidget::setData(QVector<QwtPlotCurve *>& _curve, QVector< QVector<double> >& _dataX, QVector< QVector<double> >& _dataY){
    if(_dataX.size() != _dataY.size()) return;
    if(_dataX.size() != (int) m_scales) setScales(_dataX.size());
    for(unsigned int i = 0; i < m_scales; i++){
	setData(_curve, _dataX[i], _dataY[i], i);
    }
}

void MultiScaleDetectorPlotWidget::replot(){
    m_smooth->setAxisAutoScale(0);
    m_derivative->setAxisAutoScale(0);
    m_smooth->setAxisAutoScale(2);
    m_derivative->setAxisAutoScale(2);
    m_smooth->replot();
    m_derivative->replot();
    m_smoothZoomer->setZoomBase();
    m_diffZoomer->setZoomBase();
}

