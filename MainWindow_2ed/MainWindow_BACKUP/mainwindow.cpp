#include "mainwindow.h"
#include "logowidget.h"
#include "loginwidget.h"
#include "selectwidget.h"
#include "tutorialwidget.h"
#include "shopwidget.h"
#include "statuswidget.h"
#include "replaywidget.h"
#include "itemlistwidget.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, width(850), height(600)
{
	setWindowTitle("LaserChess");
	setFixedSize(width,height);
	widget=NULL;
	this->setCursor(Qt::PointingHandCursor); //유닛잡을 때 Open&ClosedHandCursor
	
	player= new Player*[2];
	player[0]= new Player;
	player[1]= new Player;

}
void MainWindow::show(){
	QMainWindow::show();
	this->setWidget(LOGOWIDGET);
}

MainWindow::~MainWindow()
{
	player[0]->save();
	player[1]->save();
	delete player[0];
	delete player[1];
	delete[] player;
}
void MainWindow::setWidget(WIDGETTYPE _widgettype){
	widgettype=_widgettype;
	widgetChange();
}

void MainWindow::widgetChange(){
		
	if(widget)
		delete widget;
	switch(widgettype){	
	case EXIT:
		this->close();
		break;
	case LOGOWIDGET:
		widget= new LogoWidget(this);
		this->setCentralWidget(widget);
		break;
	case LOGINWIDGET:
		widget= new LoginWidget(this);
		this->setCentralWidget(widget);
		this->setWindowOpacity(1);		//추가함
		break;
	case SELECTWIDGET:
		widget= new SelectWidget(this);
		this->setCentralWidget(widget);
		break;
	case ITEMLISTWIDGET:
		widget= new ItemListWidget(player, this);
		this->setCentralWidget(widget);
		break;
	case TUTORIALWIDGET:
		widget= new TutorialWidget(this);
		this->setCentralWidget(widget);
		break;
	case SHOPWIDGET:
		widget=new ShopWidget(player, this);
		this->setCentralWidget(widget);
		break;
	case STATUSWIDGET:
		widget=new StatusWidget(player, this);
		this->setCentralWidget(widget);
		break;
	case REPLAYWIDGET:
		widget=new ReplayWidget(player, this);
		this->setCentralWidget(widget);
		break;
	}
}
void MainWindow::loginPlayer(Player** _player){
	*player[0]=*_player[0];
	*player[1]=*_player[1];
}