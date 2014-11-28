#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include "Login.h"
#include "global.h"
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlayout.h>
#include <qvalidator.h>
#include <QtWidgets/qdial.h>
#include "dialog.h"


class LoginWidget : public QWidget{
	Q_OBJECT
public:
	LoginWidget(QWidget* parent=0);
	~LoginWidget();
	Login* getLogin();
	void enterSuccess(TEAM);
	void enterComplete();
private slots:
	void enterA();
	void enterB();
	void signUp();
	void quit();
signals:
private:
	Login* login;
	QPushButton *AButton;
	QPushButton *BButton;
	QDialog *newwidget;
	QLineEdit *ALine;
	QLineEdit *BLine;
	bool success[2];
};

class signupdialog : public QDialog{
	Q_OBJECT
public:
	signupdialog(QWidget* parent=0);
private slots:
	void okay();
private:
	LoginWidget *loginwidget;
	QLineEdit* IDLine;
	QLineEdit* pwdLine;
	QLineEdit* repwdLine;
};

class enterdialog : public QDialog{
	Q_OBJECT
public:
	enterdialog(TEAM, QWidget* parent=0);
private slots:
	void okay();
private:
	LoginWidget *loginwidget;
	TEAM team;
	QLineEdit* IDLine;
	QLineEdit* pwdLine;
};