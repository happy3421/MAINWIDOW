#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QMainWindow>
#include "global.h"
#include "player.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void setWidget(WIDGETTYPE);
	void show();
	void loginPlayer(Player**);
	Player** getPlayer();
private slots:
signals:
private:
	const int width;
	const int height;
	WIDGETTYPE widgettype;
	QWidget* widget;
	Player** player;

	void widgetChange();
//	QPropertyAnimation *fadeeffect;
};

#endif // MAINWINDOW_H
