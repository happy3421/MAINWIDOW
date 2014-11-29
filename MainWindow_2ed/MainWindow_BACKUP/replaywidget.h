#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include "Replay/replay.h"
#include "global.h"

class ReplayWidget : public QWidget{
	Q_OBJECT
public:
	ReplayWidget(Player**, QWidget* parent=0);
	~ReplayWidget();
private slots:
	void goToSelect();
	void next();
private:
	QPushButton *Next;
	Replay* replay;
	QLabel* cellPic[9][9];
	ifstream replayFile;
	void setPic();
};
