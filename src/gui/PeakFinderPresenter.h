#ifndef PEAKFINDERPRESENTER_H_
#define PEAKFINDERPRESENTER_H_

#include <utils/PeakFinder.h>
#include <QtGui/QWidget>
#include <QtCore/QObject>
#include <gui/ParameterWidget.h>

class PeakFinderPresenter: public QObject{
    public:
	PeakFinderPresenter(PeakFinder* peakFinder, ParameterWidget* peakParameter):
	    m_peakFinder(peakFinder),
	    m_peakFinderParameter(peakParameter) 
	    { }

	inline void activate()
	    {if(m_peakFinderParameter) m_peakFinderParameter->activate();}
	inline void deactivate()
	    {if(m_peakFinderParameter) m_peakFinderParameter->deactivate();}

	virtual void setPeakFinder(PeakFinder* peakFinder) = 0;

	virtual void setPeakFinderParameter(ParameterWidget* peakParameter) = 0;

	    
	inline const PeakFinder* getPeakFinder() const
	    {return m_peakFinder;}
	inline const ParameterWidget* getPeakFinderParameter() const
	    {return m_peakFinderParameter;}
	
	inline PeakFinder* getPeakFinder() 
	    {return m_peakFinder;}
	inline ParameterWidget* getPeakFinderParameter() 
	    {return m_peakFinderParameter;}
	
    protected:
	PeakFinder* m_peakFinder;
	ParameterWidget* m_peakFinderParameter;
};

#endif

