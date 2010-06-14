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



#ifndef DESCRIPTORWIDGET_H_
#define DESCRIPTORWIDGET_H_

#include <QtGui/QGraphicsView>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsItem>
#include <QtGui/QMouseEvent>
#include <vector>


class DescriptorWidget: public QGraphicsView {
    Q_OBJECT
    
    public:
	DescriptorWidget(QWidget *parent = 0); 
	
	void addDescriptor(QGraphicsItem * item);

	void clear();
	
    signals:
	void descriptorSelected(int index);
	
    protected:
	virtual void mousePressEvent(QMouseEvent *event);
	
	int findDescriptor(const QGraphicsItem * item);
	
	QGraphicsScene * m_scene;
	QVector<QGraphicsItem * > m_items;

};


#endif

