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

