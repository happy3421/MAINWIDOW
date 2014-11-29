#pragma once
#include <qdialog.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
class MessageDialog : public QDialog
{
	Q_OBJECT
public:
	MessageDialog(QWidget* parent=0);
	void setText(const QString&);
	void resize(int,int);
	void setStyleSheet(const QString&);	//QPushButton
private:
	QPushButton *messageButton;
};

class DecisionDialog : public QDialog
{
	Q_OBJECT
public:
	DecisionDialog(QWidget* parent=0);
	void setText(const QString&);
private:
	QLabel *messageLabel;
	QPushButton *acceptButton;
	QPushButton *rejectButton;
};
////////////DecisionDialog 사용법
//if(decision->exec()==QDialog::Accepted){
//ok눌렀을떄의 함수}
//else{
//cancel눌렀을떄의함수}
////////////////////////////////////////////