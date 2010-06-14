/*****************************************************************
 *
 * This file is part of the FLIRTLib project
 *
 * FLIRTLib Copyright (c) 2010 Gian Diego Tipaldi and Kai O. Arras 
 *
 * This software is licensed under the "Creative Commons 
 * License (Attribution-NonCommercial-ShareAlike 3.0)" 
 * and is copyrighted by Gian Diego Tipaldi and Kai O. Arras 
 * 
 * Further information on this license can be found at:
 * http://creativecommons.org/licenses/by-nc-sa/3.0/
 * 
 * FLIRTLib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  
 *
 *****************************************************************/



#ifndef DESCRIPTORPRESENTER_H_
#define DESCRIPTORPRESENTER_H_

#include <feature/Descriptor.h>
#include <QtGui/QWidget>
#include <QtCore/QObject>
#include <gui/ParameterWidget.h>

class DescriptorPresenter: public QObject{
    public:
	DescriptorPresenter(DescriptorGenerator* descriptor, ParameterWidget* peakParameter):
	    m_descriptor(descriptor),
	    m_descriptorParameter(peakParameter) 
	    { }

	inline void activate()
	    {if(m_descriptorParameter) m_descriptorParameter->activate();}
	inline void deactivate()
	    {if(m_descriptorParameter) m_descriptorParameter->deactivate();}

	virtual void setDescriptor(DescriptorGenerator* descriptor) = 0;

	virtual void setDescriptorParameter(ParameterWidget* peakParameter) = 0;
    
	inline const DescriptorGenerator* getDescriptor() const
	    {return m_descriptor;}
	
	inline const ParameterWidget* getDescriptorParameter() const
	    {return m_descriptorParameter;}
    
	inline DescriptorGenerator* getDescriptor() 
	    {return m_descriptor;}
	
	inline ParameterWidget* getDescriptorParameter() 
	    {return m_descriptorParameter;}
	
    protected:
	DescriptorGenerator* m_descriptor;
	ParameterWidget* m_descriptorParameter;
};

#endif
