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
