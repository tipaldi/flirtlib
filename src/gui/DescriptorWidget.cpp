//
//
// FLIRTLib - Fast Laser Interesting Region Transform Library
// Copyright (C) 2009-2010 Gian Diego Tipaldi and Kai O. Arras
//
// This file is part of FLIRTLib.
//
// FLIRTLib is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// FLIRTLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with FLIRTLib.  If not, see <http://www.gnu.org/licenses/>.
//

#include "DescriptorWidget.h"
#include "DescriptorWidget.moc"

#include <iostream>

DescriptorWidget::DescriptorWidget(QWidget *parent):
    QGraphicsView(parent),
    m_items(0)
{
    m_scene = new QGraphicsScene(this);
    setScene(m_scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
}
	
void DescriptorWidget::addDescriptor(QGraphicsItem * item){
    if(!item) return;
    QRectF bounding = item->boundingRect();
    float adjust = 10.;
    float width = adjust + bounding.width()/2.;
    float height = adjust + bounding.height()/2.;
    if(!m_items.size()){
	item->setPos(width, height);
    } else {
	item->setPos(m_position.x() + width * 2., m_position.y());
    }
    m_items.push_back(item);
    m_scene->addItem(item);
    m_position = m_items.back()->pos();
    update();
}

void DescriptorWidget::addSeparator() {
    QRectF bounding = m_items.back()->boundingRect();
    float adjust = 10.;
    float height = adjust + bounding.height()/2.;
    m_position.rx() += adjust + bounding.width()/2.;
    QLineF line(m_position.x(), m_position.y() - height, m_position.x(), m_position.y() + height);
    QPen pen;
    pen.setWidth(3);
    m_scene->addLine(line, pen);
    m_position.rx() += adjust;
}

void DescriptorWidget::addNewLine() {
    QRectF bounding = m_items.front()->boundingRect();
    float adjust = 10.;
    float width = adjust + bounding.width()/2.;
    float height = adjust + bounding.height()/2.;
    m_position.rx() = -width;
    m_position.ry() += height*2.;
}    

void DescriptorWidget::clear(){
    if(m_scene) delete m_scene;
    m_scene = new QGraphicsScene(this);
    setScene(m_scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
/*    foreach(QGraphicsItem * item, m_items){
	m_scene->removeItem(item);
	delete item;
    }*/	
    m_items.clear();
//     scene->set
}
	
void DescriptorWidget::mousePressEvent(QMouseEvent *event){
    const QGraphicsItem * selected = itemAt(event->pos());
    int index = findDescriptor(selected);
    if(index > -1) emit descriptorSelected(index);
}
	
int DescriptorWidget::findDescriptor(const QGraphicsItem * item){
    int index = -1;
    for(int i = 0; i < m_items.size(); i++){
	if(m_items[i] == item){
	    index = i;
	    break;
	}
    }
    return index;
}
