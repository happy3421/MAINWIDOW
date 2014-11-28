#include "logowidget.h"
#include "mainwindow.h"
#include "qtimer.h"

LogoWidget::LogoWidget(QWidget *parent)
 : QWidget(parent)
{	
	QLabel *background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/Logo.jpg")));
	background->setScaledContents(true);
	background->resize(850,600); 

	QTimer *timer=new QTimer(this);
	timer->setSingleShot(true);
	timer->start(3000);
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(quit()));
}

void LogoWidget::quit(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(LOGINWIDGET);
}