#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qscrollarea.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qscrollbar.h>
#include "Replay/replay.h"
#include "global.h"


//�������������̸� �����ʿ�.
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
	Record *record;	//delete �����ϰ� ����� ����.
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
