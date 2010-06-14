#include "BoxParameterWidget.h"


BoxParameterWidget::BoxParameterWidget(const QString &name, QWidget *parent):
    ParameterWidget(name, parent)
{
    QGridLayout *layout = m_layout;
    m_groupBox = new QGroupBox(name, this);
    layout->addWidget(m_groupBox,0,0);
    m_layout = new QGridLayout(m_groupBox);
}

