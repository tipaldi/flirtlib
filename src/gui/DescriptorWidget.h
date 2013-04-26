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

	void addSeparator();

	void addNewLine();

	void clear();
	
    signals:
	void descriptorSelected(int index);
	
    protected:
	virtual void mousePressEvent(QMouseEvent *event);
	
	int findDescriptor(const QGraphicsItem * item);
	
	QGraphicsScene * m_scene;
	QVector<QGraphicsItem * > m_items;
	QPointF m_position;

};

#endif

