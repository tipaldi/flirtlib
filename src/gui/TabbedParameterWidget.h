#ifndef TABBEDPARAMETERWIDGET_H_
#define TABBEDPARAMETERWIDGET_H_

#include <QtGui/QTabWidget>
#include <gui/ParameterWidget.h>

class TabbedParameterWidget: public ParameterWidget {
    public:
	TabbedParameterWidget(const QString &name, QTabWidget *parent = 0, int position = -1);
	
	virtual void activate();
	    
	virtual void deactivate();
	
    protected:
	QTabWidget* m_tabWidget;
	int m_tabPosition;

};

#endif

