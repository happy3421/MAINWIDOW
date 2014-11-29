#include "itemlistwidget.h"
#include "mainwindow.h"

ItemListWidget::ItemListWidget(Player **_player, QWidget *parent)
	: QWidget(parent)
{	
	player=_player;

	shop[0]=new Shop(player[0]);
	shop[1]=new Shop(player[1]);

	QLabel *background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/test.jpg")));
	background->setScaledContents(true);
	background->resize(800,600);

	QLabel *p0=new QLabel("1P",this);
	p0->setGeometry(QRect(10,20,20,12));

	QLabel *p1=new QLabel("2P",this);
	p1->setGeometry(QRect(410,20,20,12));
	
	for(int i=0; i<2; i++) {
		for(int j=0; j<3; j++) {
			int x=player[i]->getItemE(j);
			ei[i][j]=new QLabel(this);
			ei[i][j]->setGeometry(QRect(130+400*i+90*j,10,50,50));
			if(x>-1)
				ei[i][j]->setPixmap(QPixmap(QString::fromStdString(shop[i]->ip(x)->getImage())));
			ei[i][j]->setFrameShape(QFrame::Box);
			ei[i][j]->setMargin(5);
			ei[i][j]->setScaledContents(true);
		}
	}

	QScrollArea *list[2];
	QSignalMapper *m[2][9];
	QLabel *in[2][9];

	list[0]=new QScrollArea(this);
	list[0]->setGeometry(QRect(10,70,380,400));	

	list[1]=new QScrollArea(this);
	list[1]->setGeometry(QRect(410,70,370,400));

	for(int i=0; i<2; i++) {
		for(int j=0; j<ITEMTYPE_NUM; j++) {
			int r=j%4;
			int c=j/4;
			ii[i][j]=new QPushButton(list[i]);
			ii[i][j]->setIcon(QPixmap(QString::fromStdString(shop[i]->ip(j)->getImage())));
			ii[i][j]->setIconSize(QSize(70,70));
			ii[i][j]->setGeometry(QRect(20+90*r,20+110*c,70,70));
			ii[i][j]->setFlat(1);
			if(player[i]->getItem()[j]==0)
				ii[i][j]->setEnabled(0);
			iq[i][j]=new QLabel(QString::number(player[i]->getItem()[j]),list[i]);
			iq[i][j]->setGeometry(QRect(70+90*r,70+110*c,20,20));
			iq[i][j]->setStyleSheet("QLabel { background-color : white }");
			iq[i][j]->setAlignment(Qt::AlignCenter);
			m[i][j]=new QSignalMapper(this);
			m[i][j]->setMapping(ii[i][j], j);
			QObject::connect(ii[i][j],SIGNAL(clicked()), m[i][j], SLOT(map()));
			if(i==0)
				QObject::connect(m[i][j], SIGNAL(mapped(int)), this, SLOT(equip0(int)));	
			else
				QObject::connect(m[i][j], SIGNAL(mapped(int)), this, SLOT(equip1(int)));	


			in[i][j]=new QLabel(QString::fromStdString(shop[i]->ip(j)->getName()),list[i]);
			in[i][j]->setGeometry(QRect(20+90*r,90+110*c,70,20));
			in[i][j]->setAlignment(Qt::AlignHCenter);
		}
	}
	QPushButton *back;
	back = new QPushButton("Back",this);
	back->setGeometry(QRect(20,480,100,50));
	QObject::connect(back, SIGNAL(clicked()), this, SLOT(back()));	
	
	QPushButton *next;
	next = new QPushButton("Next",this);
	next->setGeometry(QRect(680,480,100,50));
	QObject::connect(back, SIGNAL(clicked()), this, SLOT(next()));	
}
void ItemListWidget::equip0(int iid) {
	DecisionDialog *decision=new DecisionDialog(this);
	decision->setText("Are you sure?");
	if(decision->exec()==QDialog::Accepted) {
		int slot=shop[0]->equipItem(iid);
		ei[0][slot]->setPixmap(QPixmap(QString::fromStdString(shop[0]->ip(iid)->getImage())));
		iq[0][iid]->setText(QString::number(player[0]->getItem()[iid]));
		if(player[0]->getItem()[iid]==0)
			ii[0][iid]->setEnabled(0);
	}
}
void ItemListWidget::equip1(int iid) {
	DecisionDialog *decision=new DecisionDialog(this);
	decision->setText("Are you sure?");
	if(decision->exec()==QDialog::Accepted) {
		int slot=shop[1]->equipItem(iid);
		ei[1][slot]->setPixmap(QPixmap(QString::fromStdString(shop[1]->ip(iid)->getImage())));
		iq[1][iid]->setText(QString::number(player[1]->getItem()[iid]));
		if(player[1]->getItem()[iid]==0)
			ii[1][iid]->setEnabled(0);
	}
}
void ItemListWidget::back() {
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SELECTWIDGET);
}
void ItemListWidget::next() {
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(GAMEWIDGET);
}