#include "statuswidget.h"
#include "mainwindow.h"

StatusWidget::StatusWidget(Player** player, QWidget* parent)
	: QWidget(parent)
{
	record = new Record;
	record->showRecord(player[0], player[1]);
	page = 0;
	WIN = "WIN";
	LOSE = "LOSE";

	QLabel *background;
	background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/login.jpg")));
	background->setScaledContents(true);
	background->resize(850,600);

	QLabel* AID = new QLabel(player[0]->getID().c_str(), this);
	AID->setStyleSheet("color:white");
	AID->setGeometry(QRect(170, 40, 111, 61));

	QLabel* VS = new QLabel("VS", this);
	VS->setStyleSheet("color:white");
	VS->setGeometry(QRect(380, 40, 111, 61));

	QLabel* BID = new QLabel(player[1]->getID().c_str(), this);
	BID->setStyleSheet("color:white");
	BID->setGeometry(QRect(630,40, 111, 61));
	if(record->getfileExist() == 0){
		if(player[0]->getID().compare(player[1]->getID())<0){
			TEAMAWIN = to_string((long long)record->getP1Win());
			TEAMAWIN+= "Win";
			TEAMAWIN+= to_string((long long)record->getP2Win());
			TEAMAWIN+= "Lose";
			TEAMBWIN = to_string((long long)record->getP2Win());
			TEAMBWIN+= "Win";
			TEAMBWIN+= to_string((long long)record->getP1Win());
			TEAMBWIN+= "Lose";
		
		}
		else{
			TEAMBWIN = to_string((long long)record->getP1Win());
			TEAMBWIN+= "Win";
			TEAMBWIN+= to_string((long long)record->getP2Win());
			TEAMBWIN+= "Lose";
			TEAMAWIN = to_string((long long)record->getP2Win());
			TEAMAWIN+= "Win";
			TEAMAWIN+= to_string((long long)record->getP1Win());
			TEAMAWIN+= "Lose";
		}
		for(int i=0; i<10 ;i++){
			ARESULT[i]=new QLabel("", this);
			ARESULT[i]->setGeometry(QRect(150, 150+(27*i), 38, 30));
		}
		for(int i=0; i<10 ;i++){
			BRESULT[i]=new QLabel("", this);
			BRESULT[i]->setGeometry(QRect(610, 150+(27*i), 38, 30));
		}
		AWIN = new QLabel(TEAMAWIN.c_str(), this);
		AWIN->setStyleSheet("color:white");
		AWIN->setGeometry(QRect(150, 90, 111, 61));

		BWIN = new QLabel(TEAMBWIN.c_str(), this);
		BWIN->setStyleSheet("color:white");
		BWIN->setGeometry(QRect(610, 90, 111, 61));

		past = new QLabel(PAST.c_str(), this);
		past->setStyleSheet("color:white");
		past->setGeometry(QRect(320, 150, 330, 300));
		past->setAlignment(Qt::AlignTop);

		changeRecord(0);
	
		QPushButton *replay;
		replay = new QPushButton("Show Replay",this);
		replay->setGeometry(QRect(130, 440, 221, 81));
		QObject::connect(replay, SIGNAL(clicked()), this, SLOT(replay()));

		QPushButton *next= new QPushButton("next",this);
		next->setGeometry(QRect(700,100,130,70));
		QObject::connect(next, SIGNAL(clicked()), this, SLOT(next()));	

		QPushButton *before= new QPushButton("before",this);
		before->setGeometry(QRect(700,300,130,70));
		QObject::connect(before, SIGNAL(clicked()), this, SLOT(before()));
	}
	else{
		QLabel* nogame = new QLabel("There is no game between two players!!", this);
		nogame->setGeometry(QRect(320, 230, 360, 81));
	}
	QPushButton *back;
	back = new QPushButton("Back",this);
	back->setGeometry(QRect(440, 440, 221, 81));
	QObject::connect(back, SIGNAL(clicked()), this, SLOT(goToSelect()));

}

void StatusWidget::next(){
	if(page<2)
		changeRecord(++page);
}
void StatusWidget::before(){
	if(page>0)
		changeRecord(--page);
}
void StatusWidget::changeRecord(int page){
	int i;
	PAST = "";
	switch(page){
	case 0:
		if(record->gethowMany() <= 10){
			for(i=0;i<record->gethowMany();i++){
				PAST += to_string((long long)record->gettimeRecord()[i][0]);
				PAST += ".";
				if(record->gettimeRecord()[i][1]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][1]);
				PAST += ".";
				if(record->gettimeRecord()[i][2]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][2]);
				PAST += "\t";
				if(record->gettimeRecord()[i][3]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][3]);
				PAST += ":";
				if(record->gettimeRecord()[i][4]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][4]);
				PAST += "\n\n";
				if(record->gettimeRecord()[i][5] == 0){
					ARESULT[i]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.png")));
					BRESULT[i]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.png")));
				}
				else{
					ARESULT[i]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.png")));
					BRESULT[i]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.png")));
				}
			}
			for(int j=i; j<10;j++){
				ARESULT[j]->setPixmap(QPixmap(QString::fromUtf8("")));
				BRESULT[j]->setPixmap(QPixmap(QString::fromUtf8("")));
			}
			past->setText(PAST.c_str());
		}
		else{
			for(int i=0;i<10;i++){
				PAST += to_string((long long)record->gettimeRecord()[i][0]);
				PAST += ".";
				if(record->gettimeRecord()[i][1]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][1]);
				PAST += ".";
				if(record->gettimeRecord()[i][2]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][2]);
				PAST += "\t";
				if(record->gettimeRecord()[i][3]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][3]);
				PAST += ":";
				if(record->gettimeRecord()[i][4]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][4]);
				PAST += "\n\n";
				if(record->gettimeRecord()[i][5] == 0){
					ARESULT[i]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.png")));
					BRESULT[i]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.png")));
				}
				else{
					ARESULT[i]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.png")));
					BRESULT[i]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.png")));
				}
			}
			past->setText(PAST.c_str());
		}
		break;
	case 1:
		if(record->gethowMany() <= 20){
			for(i=10;i<record->gethowMany();i++){
				PAST += to_string((long long)record->gettimeRecord()[i][0]);
				PAST += ".";
				if(record->gettimeRecord()[i][1]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][1]);
				PAST += ".";
				if(record->gettimeRecord()[i][2]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][2]);
				PAST += "\t";
				if(record->gettimeRecord()[i][3]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][3]);
				PAST += ":";
				if(record->gettimeRecord()[i][4]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][4]);
				PAST += "\n\n";
				if(record->gettimeRecord()[i][5] == 0){
					ARESULT[i-10]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.png")));
					BRESULT[i-10]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.png")));
				}
				else{
					ARESULT[i-10]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.png")));
					BRESULT[i-10]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.png")));
				}
			}
			for(int j=i; j<20;j++){
				ARESULT[j-10]->setPixmap(QPixmap(QString::fromUtf8("")));
				BRESULT[j-10]->setPixmap(QPixmap(QString::fromUtf8("")));
			}
			past->setText(PAST.c_str());
		}
		else{
			for(int i=10;i<20;i++){
				PAST += to_string((long long)record->gettimeRecord()[i][0]);
				PAST += ".";
				if(record->gettimeRecord()[i][1]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][1]);
				PAST += ".";
				if(record->gettimeRecord()[i][2]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][2]);
				PAST += "\t";
				if(record->gettimeRecord()[i][3]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][3]);
				PAST += ":";
				if(record->gettimeRecord()[i][4]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][4]);
				PAST += "\n\n";
				if(record->gettimeRecord()[i][5] == 0){
					ARESULT[i-10]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.jpg")));
					BRESULT[i-10]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.jpg")));
				}
				else{
					ARESULT[i-10]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.jpg")));
					BRESULT[i-10]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.jpg")));
				}
			}
			past->setText(PAST.c_str());
		}
		break;
	case 2:
		if(record->gethowMany() <= 30){
			for(i=20;i<record->gethowMany();i++){
				PAST += to_string((long long)record->gettimeRecord()[i][0]);
				PAST += ".";
				if(record->gettimeRecord()[i][1]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][1]);
				PAST += ".";
				if(record->gettimeRecord()[i][2]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][2]);
				PAST += "\t";
				if(record->gettimeRecord()[i][3]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][3]);
				PAST += ":";
				if(record->gettimeRecord()[i][4]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][4]);
				PAST += "\n\n";
				if(record->gettimeRecord()[i][5] == 0){
					ARESULT[i-20]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.jpg")));
					BRESULT[i-20]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.jpg")));
				}
				else{
					ARESULT[i-20]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.jpg")));
					BRESULT[i-20]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.jpg")));
				}
			}
			for(int j=i; j<30;j++){
				ARESULT[j-20]->setPixmap(QPixmap(QString::fromUtf8("")));
				BRESULT[j-20]->setPixmap(QPixmap(QString::fromUtf8("")));
			}
			past->setText(PAST.c_str());
		}
		else{
			for(int i=20;i<30;i++){
				PAST += to_string((long long)record->gettimeRecord()[i][0]);
				PAST += ".";
				if(record->gettimeRecord()[i][1]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][1]);
				PAST += ".";
				if(record->gettimeRecord()[i][2]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][2]);
				PAST += "\t";
				if(record->gettimeRecord()[i][3]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][3]);
				PAST += ":";
				if(record->gettimeRecord()[i][4]<10)
					PAST += "0";
				PAST += to_string((long long)record->gettimeRecord()[i][4]);
				PAST += "\n\n";
				if(record->gettimeRecord()[i][5] == 0){
					ARESULT[i-20]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.jpg")));
					BRESULT[i-20]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.jpg")));
				}
				else{
					ARESULT[i-20]->setPixmap(QPixmap(QString::fromUtf8("Resources/lose.jpg")));
					BRESULT[i-20]->setPixmap(QPixmap(QString::fromUtf8("Resources/win.jpg")));
				}
			}
			past->setText(PAST.c_str());
		}
		break;
	}
}
StatusWidget::~StatusWidget(){
	delete record;
}
void StatusWidget::goToSelect(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SELECTWIDGET);
}
void StatusWidget::replay(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(REPLAYWIDGET);
}
