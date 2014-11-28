#include "selectwidget.h"
#include "mainwindow.h"

SelectWidget::SelectWidget(QWidget *parent)
 : QWidget(parent)
{	
	QLabel *background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/select.jpg")));
	background->setScaledContents(true);
	background->resize(850,600);

	QPushButton *gamestart= new QPushButton(this);
	gamestart->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/startbutton.jpg)} QPushButton:pressed { border-image: url(Resources/startbutton2.jpg)}");
	gamestart->setGeometry(QRect(475,125,150,80));
	QObject::connect(gamestart, SIGNAL(clicked()), this, SLOT(goToGame()));

	QPushButton *tutorial= new QPushButton(this);
	tutorial->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/tutorialbutton.jpg)} QPushButton:pressed { border-image: url(Resources/tutorialbutton2.jpg)}");
	tutorial->setGeometry(QRect(475,425,150,80));
	QObject::connect(tutorial, SIGNAL(clicked()), this, SLOT(goToTutorial()));	

	QPushButton *shop= new QPushButton(this);
	shop->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/shopbutton.jpg)} QPushButton:pressed { border-image: url(Resources/shopbutton2.jpg)}");
	shop->setGeometry(QRect(650,225,150,80));
	QObject::connect(shop, SIGNAL(clicked()), this, SLOT(goToShop()));	

	QPushButton *status= new QPushButton(this);
	status->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/statusbutton.jpg)} QPushButton:pressed { border-image: url(Resources/statusbutton2.jpg)}");
	status->setGeometry(QRect(650,325,150,80));
	QObject::connect(status, SIGNAL(clicked()), this, SLOT(goToStatus()));	

	QPushButton *exit= new QPushButton(this);
	exit->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/exit.jpg)} QPushButton:pressed { border-image: url(Resources/exit_2.jpg)}");
	exit->setGeometry(QRect(790,10,50,50)); 
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(quit()));	
}
void SelectWidget::goToGame(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(ITEMLISTWIDGET);
}
void SelectWidget::goToTutorial(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(TUTORIALWIDGET);
}
void SelectWidget::goToShop(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SHOPWIDGET);
}
void SelectWidget::goToStatus(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(STATUSWIDGET);
}
void SelectWidget::quit(){
	DecisionDialog* decision=new DecisionDialog(this);
	decision->setText("Are you sure?");
	if(decision->exec()==QDialog::Accepted){
		MainWindow* mainwindow;
		mainwindow=static_cast<MainWindow*>(this->parentWidget());
		mainwindow->setWidget(EXIT);
	}
}