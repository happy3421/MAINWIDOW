#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <qpropertyanimation.h>
#include <qthread.h>
//#include "qtimer.h"
#include "global.h"
class LogoWidget : public QWidget{
	Q_OBJECT
public:
	LogoWidget(QWidget* parent=0);
private slots:
	void fadeIn();
	void fadeOut();
	void quit();
private:
	QPropertyAnimation *fadein;
	QPropertyAnimation *fadeout;
};
