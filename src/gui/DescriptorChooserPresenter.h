#ifndef DESCRIPTORCHOOSERPRESENTER_H_
#define DESCRIPTORCHOOSERPRESENTER_H_

#include <gui/DescriptorPresenter.h>
#include <gui/ParameterWidget.h>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QGridLayout>
#include <QtCore/QVector>
#include <QtCore/QObject>
#include <QtCore/QString>

// class DescriptorChooserWidget: public QWidget{
//     Q_OBJECT
//     
//     public:
// 	DescriptorChooserWidget(QWidget * parent = 0);
//     
// 	inline int getDescriptor() const
// 	    {return m_descriptor.currentIndex();}
// 	inline void insertDescriptor(const QString& name)
// 	    {m_descriptor.addItem(name);}
// 	    
// 	void resetDescriptor();
// 	
//     signals:
// 	void descriptorChanged(int descriptor);
// 	
//     public slots:
// 	void changeDescriptor(int descriptor);
// 	
//     protected:
// 	void buildGui();
// 	
// 	QComboBox m_descriptor;
// 	QLabel m_descriptorLabel;
// 	QGridLayout m_layout;
// 
// };

class DescriptorChooserPresenter: public QObject{
    Q_OBJECT

    public:
	DescriptorChooserPresenter(ParameterWidget* chooser);
	
	void insertDescriptor(const QString& name, DescriptorPresenter* descriptor);

	void setChooser(ParameterWidget* chooser);
	
	inline const ParameterWidget* getChooserParameter() const
	    {return m_chooser;}
	
	inline const DescriptorPresenter* getCurrentDescriptorPresenter() const
	    {return m_currentDescriptorPresenter;}
	
	inline const DescriptorGenerator* getCurrentDescriptor() const
	    {return m_currentDescriptorPresenter->getDescriptor();}
	
	inline ParameterWidget* getChooserParameter() 
	    {return m_chooser;}
	
	inline DescriptorPresenter* getCurrentDescriptorPresenter() 
	    {return m_currentDescriptorPresenter;}
	
	inline DescriptorGenerator* getCurrentDescriptor() 
	    {return m_currentDescriptorPresenter->getDescriptor();}
		
    signals:
	void descriptorChanged();
	
    public slots:
	void changeDescriptor(int descriptor);	
	void changeParameter(const QString& name);	

    protected:
	void syncronize();
	void reconnect();
	ParameterWidget* m_chooser;
	DescriptorPresenter* m_currentDescriptorPresenter;
	int m_currentDescriptorPresenterIndex;
	QVector< DescriptorPresenter* > m_descriptorPresenters;
	QStringList m_descriptorPresenterNames;
};

#endif

