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
    float width = adjust + bounding.width();
    float height = adjust + bounding.height();
    item->setPos(m_position.x(), m_position.y());
    m_items.push_back(item);
    m_scene->addItem(item);
    m_position.rx() += width + adjust;
    update();
}

void DescriptorWidget::addSeparator() {
    if(!m_items.size()) return;
    QRectF bounding = m_items.front()->boundingRect();
    float adjust = 10.;
    float height = adjust + bounding.height();
    QLineF line(m_position.x(), m_position.y(), m_position.x(), m_position.y() + height);
    QPen pen;
    pen.setWidth(3);
    m_scene->addLine(line, pen);
    m_position.rx() += adjust + pen.widthF();
}

void DescriptorWidget::addNewLine() {
    QRectF bounding = m_items.front()->boundingRect();
    float adjust = 10.;
    float width = adjust + bounding.width();
    float height = adjust + bounding.height();
    m_position.rx() = m_items.front()->x();
    m_position.ry() += height;
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
