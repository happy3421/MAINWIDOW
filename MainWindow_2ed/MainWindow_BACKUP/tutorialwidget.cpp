#include "tutorialwidget.h"
#include "mainwindow.h"
#define TUTORIAL_NUM 4

TutorialWidget::TutorialWidget(QWidget *parent)
 : QWidget(parent)
{	
	page=0;

	QLabel *background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/test3.jpg")));
	background->setScaledContents(true);
	background->resize(850,600);

	tutorial=new QLabel(this);
	tutorial->setPixmap(QPixmap(QString::fromUtf8("Resources/tutorial0.jpg")));
	tutorial->setScaledContents(true);
	tutorial->resize(550,300);
//	tutorial->move(0,0);

	QPushButton *next= new QPushButton("next",this);
	next->setGeometry(QRect(600,100,200,100));
	QObject::connect(next, SIGNAL(clicked()), this, SLOT(next()));	

	QPushButton *before= new QPushButton("before",this);
	before->setGeometry(QRect(600,300,200,100));
	QObject::connect(before, SIGNAL(clicked()), this, SLOT(before()));	

	QPushButton *exit= new QPushButton("return",this);
	exit->setGeometry(QRect(600,500,200,100));
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(goToSelect()));	
}

void TutorialWidget::showTutorial(int page)
{
	switch(page){
	case 0:
		tutorial->setPixmap(QPixmap(QString::fromUtf8("Resources/tutorial0.jpg")));
		break;
	case 1:
		tutorial->setPixmap(QPixmap(QString::fromUtf8("Resources/tutorial1.jpg")));
		break;
	case 2:
		tutorial->setPixmap(QPixmap(QString::fromUtf8("Resources/tutorial2.jpg")));
		break;
	case 3:
		tutorial->setPixmap(QPixmap(QString::fromUtf8("Resources/tutorial3.jpg")));
		break;
	}
}

void TutorialWidget::next(){
	if(page<TUTORIAL_NUM-1)
		showTutorial(++page);
}
void TutorialWidget::before(){
	if(page>0)
		showTutorial(--page);
}
void TutorialWidget::goToSelect(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SELECTWIDGET);
}