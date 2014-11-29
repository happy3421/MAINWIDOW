#include "logowidget.h"
#include "mainwindow.h"

LogoWidget::LogoWidget(QWidget *parent)
 : QWidget(parent)
{	
	fadein = new QPropertyAnimation(this->parent(), "windowOpacity");
	QObject::connect(fadein, SIGNAL(finished()), this, SLOT(fadeOut()));
	
	fadeout = new QPropertyAnimation(this->parent(), "windowOpacity");
	QObject::connect(fadeout, SIGNAL(finished()), this, SLOT(quit()));

	QLabel *background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/Logo.jpg")));
	background->setScaledContents(true);
	background->resize(850,600); 

	fadeIn();
//	QTimer *timer=new QTimer(this);
//	timer->setSingleShot(true);
//	timer->start(3000);
//	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(quit()));
}
void LogoWidget::fadeIn(){
	fadein->setDuration(1618);
	fadein->setStartValue(0.0);
	fadein->setEndValue(1.0);
	fadein->start(QAbstractAnimation::DeleteWhenStopped);
}
void LogoWidget::fadeOut(){
	QThread::msleep(2718);

	fadeout->setDuration(1414);
	fadeout->setStartValue(1.0);
	fadeout->setEndValue(0.0);
	fadeout->start(QAbstractAnimation::DeleteWhenStopped);
}
void LogoWidget::quit(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(LOGINWIDGET);
}