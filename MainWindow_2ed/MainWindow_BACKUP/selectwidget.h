#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include "global.h"
#include "dialog.h"
class SelectWidget : public QWidget{
	Q_OBJECT
public:
	SelectWidget(QWidget* parent=0);
private slots:
	void goToGame();
	void goToTutorial();
	void goToShop();
	void goToStatus();
	void quit();
private:
};
