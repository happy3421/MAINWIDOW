#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qspinbox.h>
#include <QtWidgets/qscrollarea.h>
#include <QtWidgets/qdialog.h>
#include <qsignalmapper.h>
#include "player.h"
#include "item/shop.h"
#include "global.h"
#include "dialog.h"

class ShopWidget : public QWidget{
	Q_OBJECT
public:
	ShopWidget(Player**, QWidget* parent=0);
	~ShopWidget();
	Shop* getShop(int i);
	Player* getPlayer(int i);
	QLabel* getGold(int i);
private slots:
	void buy0(int iid);
	void buy1(int iid);
	void back();
private:
	QDialog* newdialog;
	QLabel* pg[2];
	Shop *shop[2];
	Player** player;
};

class BuyDialog:public QDialog{
	Q_OBJECT
public:
	BuyDialog(int pid, int iid, QWidget* parent=0);
private slots:
	void buy();
private:
	int pid;
	int iid;
	ShopWidget* sw;
	QSpinBox* isb;
};