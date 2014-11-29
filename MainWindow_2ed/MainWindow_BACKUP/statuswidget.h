#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qscrollarea.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qscrollbar.h>
#include "Replay/replay.h"
#include "global.h"


//전적저장파일이름 변경필요.
class StatusWidget : public QWidget{
	Q_OBJECT
public:
	StatusWidget(Player**, QWidget* parent=0);
	~StatusWidget();	//delete record
private slots:
	void goToSelect();
	void replay();
	void next();
	void before();
private:
	Record *record;	//delete 가능하게 멤버로 선언.
	int page;
	string WIN;
	string LOSE;
	string TEAMAWIN;
	string TEAMBWIN;
	string PAST;
	QLabel* AWIN;
	QLabel* BWIN;
	QLabel* past;
	QLabel* ARESULT[10];
	QLabel* BRESULT[10];
	void changeRecord(int);
};
