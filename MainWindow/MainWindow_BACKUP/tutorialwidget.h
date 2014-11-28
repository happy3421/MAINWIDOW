#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include "global.h"
class TutorialWidget : public QWidget{
	Q_OBJECT
public:
	TutorialWidget(QWidget* parent=0);
private slots:
	void next();
	void before();
	void goToSelect();
private:
	int page;
	QLabel *tutorial;
	void showTutorial(int);
};
