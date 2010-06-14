#include "gui/TabbedParameterWidget.h"

TabbedParameterWidget::TabbedParameterWidget(const QString &name, QTabWidget *parent, int position):
    ParameterWidget(name, 0),
    m_tabWidget(parent),
    m_tabPosition(position)
{
    if(m_tabWidget && position == -1)
	m_tabPosition = m_tabWidget->count();
}

void TabbedParameterWidget::activate()
{
    ParameterWidget::activate(); 
    if(m_tabWidget){
	m_tabWidget->insertTab(m_tabPosition, this, m_name);
// 	m_tabWidget->setCurrentIndex(position);
    }
}
    
void TabbedParameterWidget::deactivate()
{
    ParameterWidget::deactivate(); 
    if(m_tabWidget){
	int position = m_tabWidget->indexOf(this);
	m_tabWidget->removeTab(position);
    }
}
