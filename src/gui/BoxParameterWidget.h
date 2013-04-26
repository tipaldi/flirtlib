#ifndef BOXPARAMETERWIDGET_H_
#define BOXPARAMETERWIDGET_H_

#include <QtGui/QGroupBox>
#include <gui/ParameterWidget.h>

class BoxParameterWidget: public ParameterWidget {
    public:
	BoxParameterWidget(const QString &name, QWidget *parent = 0);
    
    protected:
	QGroupBox *m_groupBox;
};

#endif

