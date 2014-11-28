#include "replaywidget.h"
#include "mainwindow.h"

ReplayWidget::ReplayWidget(Player** player, QWidget* parent){
	replay = new Replay;
	
	replay->getInfo(player[0], player[1]);
	QLabel* AID = new QLabel(player[0]->getID().c_str(), this);
	AID->setGeometry(QRect(250, 20, 56, 12));

	QLabel* BID = new QLabel(player[1]->getID().c_str(), this);
	BID->setGeometry(QRect(250, 570, 56, 12));

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cellPic[i][j] = new QLabel(this);
			cellPic[i][j]->setGeometry(QRect(60+(50*j), 40+(50*i), 41, 41));
		}
	}

	Next= new QPushButton("next",this);
	Next->setGeometry(QRect(630, 160, 121, 71));
	QObject::connect(Next, SIGNAL(clicked()), this, SLOT(next()));	

	QPushButton *exit= new QPushButton("return",this);
	exit->setGeometry(QRect(690, 500, 111, 71));
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(goToSelect()));	
	
	replay->showReplay();
	setPic();
	replay->showReplay();
}

ReplayWidget::~ReplayWidget(){
	delete replay;
}
void ReplayWidget::next(){
	if(replay->getCellStr(8, 8) < 0)
		delete Next;
	else{
		setPic();
	}
	replay->showReplay();
}
void ReplayWidget::setPic(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			switch(replay->getCellStr(i, j)){
			case 111:
				cellPic[i][j]->setPixmap(QPixmap(QString::fromUtf8("Resources/character111.jpg")));
				break;
			case 112:
				cellPic[i][j]->setPixmap(QPixmap(QString::fromUtf8("Resources/character112.jpg")));
				break;
			case 113:
				cellPic[i][j]->setPixmap(QPixmap(QString::fromUtf8("Resources/character113.jpg")));
				break;
			//�׸������� character000.jpg�� ������ ���ھ� 000�� ���� ���ڸ��� ���ǵ� ù�ڸ��� ���� ��, �ι�° �ڸ��� ���� ����, ����° �ڸ��� ���� ������... enum������� 1���� �آa
			}
		}
	}
	
}

void ReplayWidget::goToSelect(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SELECTWIDGET);
}