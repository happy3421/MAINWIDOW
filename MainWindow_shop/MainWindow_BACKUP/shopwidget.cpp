#include "shopwidget.h"
#include "mainwindow.h"

ShopWidget::ShopWidget(Player **_player, QWidget *parent)
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

	pg[0]=new QLabel(QString::number(player[0]->getMoney()),this);
	pg[0]->setGeometry(QRect(290,20,60,12));
	pg[0]->setAlignment(Qt::AlignRight);

	QLabel *g0=new QLabel(" Gold",this);
	g0->setGeometry(QRect(350,20,30,12));
	g0->setAlignment(Qt::AlignRight);

	pg[1]=new QLabel(QString::number(player[1]->getMoney()),this);
	pg[1]->setGeometry(QRect(690,20,60,12));
	pg[1]->setAlignment(Qt::AlignRight);

	QLabel *g1=new QLabel(" Gold",this);
	g1->setGeometry(QRect(750,20,30,12));
	g1->setAlignment(Qt::AlignRight);

	QScrollArea *list[2];
	QPushButton *ii[2][9];
	QSignalMapper *m[2][9];
	QLabel *in[2][9];

	list[0]=new QScrollArea(this);
	list[0]->setGeometry(QRect(10,50,380,400));	

	list[1]=new QScrollArea(this);
	list[1]->setGeometry(QRect(410,50,370,400));

	for(int i=0; i<2; i++) {
		for(int j=0; j<ITEMTYPE_NUM; j++) {
			int r=j%4;
			int c=j/4;
			ii[i][j]=new QPushButton(list[i]);
			ii[i][j]->setIcon(QPixmap(QString::fromStdString(shop[i]->ip(j)->getImage())));
			ii[i][j]->setIconSize(QSize(70,70));
			ii[i][j]->setGeometry(QRect(20+90*r,20+110*c,70,70));
			ii[i][j]->setFlat(1);
			iq[i][j]=new QLabel(QString::number(player[i]->getItem()[j]),list[i]);
			iq[i][j]->setGeometry(QRect(70+90*r,70+110*c,20,20));
			iq[i][j]->setStyleSheet("QLabel { background-color : white }");
			iq[i][j]->setAlignment(Qt::AlignCenter);
			m[i][j]=new QSignalMapper(this);
			m[i][j]->setMapping(ii[i][j], j);
			QObject::connect(ii[i][j],SIGNAL(clicked()), m[i][j], SLOT(map()));
			if(i==0)
				QObject::connect(m[i][j], SIGNAL(mapped(int)), this, SLOT(buy0(int)));	
			else
				QObject::connect(m[i][j], SIGNAL(mapped(int)), this, SLOT(buy1(int)));	

			in[i][j]=new QLabel(QString::fromStdString(shop[i]->ip(j)->getName()),list[i]);
			in[i][j]->setGeometry(QRect(20+90*r,90+110*c,70,20));
			in[i][j]->setAlignment(Qt::AlignHCenter);
		}
	}

	QPushButton *back;
	back = new QPushButton("Back",this);
	back->setGeometry(QRect(680,480,100,50));
	QObject::connect(back, SIGNAL(clicked()), this, SLOT(back()));	
}
ShopWidget::~ShopWidget(){
	delete shop[0];
	delete shop[1];
}
Player* ShopWidget::getPlayer(int i) {return player[i];}
Shop* ShopWidget::getShop(int i) {return shop[i];}
QLabel* ShopWidget::getGold(int i) {return pg[i];}
QLabel* ShopWidget::getQuantity(int pid, int iid) {return iq[pid][iid];}
void ShopWidget::buy0(int iid) {
	newdialog= new BuyDialog(0,iid,this);
	newdialog->exec();
	delete newdialog;
}
void ShopWidget::buy1(int iid) {
	newdialog= new BuyDialog(1,iid,this);
	newdialog->exec();
	delete newdialog;
}
void ShopWidget::back() {
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->setWidget(SELECTWIDGET);
}
BuyDialog::BuyDialog(int pidi, int iidi, QWidget* parent)
	: QDialog(parent)
{
	sw=static_cast<ShopWidget*>(parent);
	pid=pidi;
	iid=iidi;
	Item* item=sw->getShop(pid)->ip(iid);

	QLabel *background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/test.jpg")));
	background->setScaledContents(true);
	background->resize(350,180);

	QLabel *ii=new QLabel(this);
	ii->setGeometry(QRect(20,20,80,80));
	ii->setPixmap(QPixmap(QString::fromStdString(item->getImage())));
	ii->setScaledContents(true);

	QLabel *iname=new QLabel(QString::fromStdString(item->getName()), this);
	iname->setGeometry(QRect(120,20,200,20));
	iname->setAlignment(Qt::AlignHCenter);

	QLabel *idesc=new QLabel(QString::fromStdString(item->getDesc()), this);
	idesc->setGeometry(QRect(120,60,200,60));
	idesc->setAlignment(Qt::AlignTop);

	isb=new QSpinBox(this);
	isb->setGeometry(QRect(40,110,40,20));
	isb->setMinimum(1);
	isb->setVisible(1);

	QPushButton *buy=new QPushButton("Buy", this);
	buy->setGeometry(QRect(70,140,80,30));
	QObject::connect(buy,SIGNAL(clicked()), this, SLOT(buy()));

	QPushButton *cancel=new QPushButton("Cancel", this);
	cancel->setGeometry(QRect(200,140,80,30));
	QObject::connect(cancel,SIGNAL(clicked()), this, SLOT(close()));
}
void BuyDialog::buy() {
	DecisionDialog *decision=new DecisionDialog(this);
	decision->setText("Are you sure?");
	if(decision->exec()==QDialog::Accepted) {
		int n=isb->value();
		bool x=sw->getShop(pid)->buyItem(iid,isb->value());
		if(x) {
			sw->getGold(pid)->setText(QString::number(sw->getPlayer(pid)->getMoney()));
			sw->getQuantity(pid,iid)->setText(QString::number(sw->getPlayer(pid)->getItem()[iid]));
		}
		else {
			QMessageBox* error=new QMessageBox(this);
			error->setIcon(QMessageBox::Critical);
			error->setText("Not Enough Money");
			error->exec();
		}
		this->close();
	}
}