#include "loginwidget.h"
#include "mainwindow.h"

LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{	
	login=new Login;
	newwidget=new QDialog(this);
	success[0]=false;
	success[1]=false;

	QLabel *background;
	background=new QLabel(this);
	background->setPixmap(QPixmap(QString::fromUtf8("Resources/login.jpg")));
	background->setScaledContents(true);
	background->resize(850,600);

	QPushButton *exit;
	exit = new QPushButton(this); 
	exit->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/exit.jpg)} QPushButton:pressed { border-image: url(Resources/exit_2.jpg)}");
	exit->setGeometry(QRect(790,10,50,50)); 
	QObject::connect(exit, SIGNAL(clicked()), this, SLOT(quit()));	

	AButton = new QPushButton(this);
	AButton->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/loginA1.jpg)} QPushButton:pressed { border-image: url(Resources/loginA2.jpg)}");
	AButton->setGeometry(QRect(150,440,150,100));
	QObject::connect(AButton, SIGNAL(clicked()), this, SLOT(enterA()));

	BButton = new QPushButton(this); 
	BButton->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/loginB1.jpg)} QPushButton:pressed { border-image: url(Resources/loginB2.jpg)}");
	BButton->setGeometry(QRect(350,440,150,100));
	QObject::connect(BButton, SIGNAL(clicked()), this, SLOT(enterB()));

	QPushButton *signup;
	signup = new QPushButton(this);
	signup->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/signup1.jpg)} QPushButton:pressed { border-image: url(Resources/signup2.jpg)}");
	signup->setGeometry(QRect(600,440,150,100));

	QObject::connect(signup, SIGNAL(clicked()), this, SLOT(signUp()));

	//ALine = new QLineEdit("  Go To LoginA",this);
	//ALine->setGeometry(QRect(275,530,100,50));
	//ALine->setReadOnly(true);
	//ALine->setStyleSheet("color: white;" "background-color: black;" "selection-color: black;" "selection-background-color: black;");
	//ALine->setStyleSheet("QLineEdit { background-image: url(loginline.jpg)}");

	//BLine = new QLineEdit("  Go To LoginB",this);
	//BLine->setGeometry(QRect(475,530,100,50));
	//BLine->setReadOnly(true);
	//BLine->setStyleSheet("color: white;" "background-color: black;" "selection-color: black;" "selection-background-color: black;");
}

LoginWidget::~LoginWidget(){
	delete newwidget;
	delete login;
}
void LoginWidget::quit(){
	DecisionDialog* decision=new DecisionDialog(this);
	decision->setText("Are you sure?");
	if(decision->exec()==QDialog::Accepted){
		MainWindow* mainwindow;
		mainwindow=static_cast<MainWindow*>(this->parentWidget());
		mainwindow->setWidget(EXIT);
	}
}
void LoginWidget::signUp(){
	delete newwidget;
	newwidget=new signupdialog(this);
	newwidget->exec();
}

void LoginWidget::enterA(){
	if(success[0]){
		MessageDialog* message=new MessageDialog(this);
		message->setText("already");
		message->exec();
	}
	else{
		delete newwidget;
		newwidget=new enterdialog(ATEAM, this);
		if(newwidget->exec()==QDialog::Accepted)
			enterSuccess(ATEAM);
	}
}
void LoginWidget::enterB(){
	if(success[1]){
		MessageDialog* message=new MessageDialog(this);
		message->setText("already");
		message->exec();
	}
	else{
		delete newwidget;
		newwidget=new enterdialog(BTEAM, this);
		if(newwidget->exec()==QDialog::Accepted)
			enterSuccess(BTEAM);
	}
}

void LoginWidget::enterSuccess(TEAM _team){
	int team=static_cast<int>(_team);
	success[team]=true;

	if(_team==ATEAM)	
		AButton->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/logins.jpg)} QPushButton:pressed { border-image: url(Resources/logins.jpg)}");
	else if(_team==BTEAM)	
		BButton->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/logins.jpg)} QPushButton:pressed { border-image: url(Resources/logins.jpg)}");

	if(success[0] & success[1]){
		MessageDialog* message=new MessageDialog(this);
		message->setText("success!! press OK");
		message->exec();

		enterComplete();
	}
}
void LoginWidget::enterComplete(){
	MainWindow* mainwindow;
	mainwindow=static_cast<MainWindow*>(this->parentWidget());
	mainwindow->loginPlayer(this->login->getPlayer());	//로그인정보를 mainwindow에 옮김
	mainwindow->setWidget(SELECTWIDGET);
}

Login* LoginWidget::getLogin(){return login;}
///////////////////////////////////////////////////////////////////////////
signupdialog::signupdialog(QWidget *parent) //
	: QDialog(parent)
{	


	loginwidget=static_cast<LoginWidget*>(parent);

	IDLine = new QLineEdit();
	IDLine->setEchoMode(QLineEdit::Normal);
	IDLine->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_]+"), this ));//알파벳숫자만입력.하나이상입력.
	//IDLine->setStyleSheet("color: black;" " background-image: url(Resources/white.jpg);");
	IDLine->setFixedSize(200,20);
	
	pwdLine = new QLineEdit();
	pwdLine->setEchoMode(QLineEdit::Password);
	pwdLine->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_]+"), this ));
	//pwdLine->setStyleSheet("color: black;" " background-image: url(Resources/white.jpg);");
	pwdLine->setFixedSize(200,20);

	repwdLine = new QLineEdit();
	repwdLine->setEchoMode(QLineEdit::Password);
	repwdLine->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_]+"), this ));
	//repwdLine->setStyleSheet("color: black;" " background-image: url(Resources/white.jpg);");
	repwdLine->setFixedSize(200,20);

	QHBoxLayout *IDBox= new QHBoxLayout;
	QWidget* id=new QLabel("ID");
	//id->setStyleSheet("color: white;" "font: 18pt;");
	id->setGeometry(9,9,50,25);
	IDBox->addWidget(id);
	IDBox->addWidget(IDLine);
	

	QHBoxLayout *pwdBox= new QHBoxLayout;
	QWidget* pwd=new QLabel("PWD");
	//pwd->setStyleSheet("color: white;" "font: 18pt;");
	pwdBox->addWidget(pwd);
	pwdBox->addWidget(pwdLine);
	
	QHBoxLayout *repwdBox= new QHBoxLayout;
	QWidget* rpd=new QLabel("REPWD");
	//rpd->setStyleSheet("color: white;" "font: 18pt;");
	repwdBox->addWidget(rpd);
	repwdBox->addWidget(repwdLine);

	//this->setStyleSheet("background-image: url(Resources/loginbackground.jpg);");

	//addLayout; VBox <= IDBox, pwdBox, repwdBox
	//setLayout; this <= VBox
	//setLayout; this <= addwidgets

	QPushButton* okay=new QPushButton("okay",this);
	QObject::connect(okay, SIGNAL(clicked()), this, SLOT(okay()));

	QPushButton* cancel=new QPushButton("cancel",this);
	QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *buttonBox= new QHBoxLayout;
	buttonBox->addWidget(okay);
	buttonBox->addWidget(cancel);
	
	QVBoxLayout *VBox=new QVBoxLayout;
	VBox->addLayout(IDBox);
	VBox->addLayout(pwdBox);
	VBox->addLayout(repwdBox);
	VBox->addLayout(buttonBox);

	setLayout(VBox);
	this->setFixedSize(300,200);
}

void signupdialog::okay(){
	//QString->QByteArray->char*
	//QByteArray _id=IDLine->text().toLocal8Bit();
	//QByteArray _pwd=pwdLine->text().toLocal8Bit();
	//QByteArray _repwd=repwdLine->text().toLocal8Bit();
	//char* id=_id.data();
	//char* pwd=_pwd.data();
	//char* repwd=_repwd.data();
	string id=IDLine->text().toStdString();
	string pwd=pwdLine->text().toStdString();
	string repwd=repwdLine->text().toStdString();
	int signup = loginwidget->getLogin()->signUp(id,pwd,repwd);
	if(signup==EXISTING_ID){
		MessageDialog* message=new MessageDialog(this);	
		message->setText("existing_id");
		message->setStyleSheet("QPushButton:!pressed {border-image: url(Resources/exit.jpg)} QPushButton:pressed { border-image: url(Resources/exit_2.jpg)}");
		message->resize(100,50);
		message->exec();			
	}
	else if(signup==NO_ID){
		MessageDialog* message=new MessageDialog(this);
		message->setText("please enter ID");
		message->exec();
	}
	else if(signup==NO_PWD){
		MessageDialog* message=new MessageDialog(this);
		message->setText("please enter PWD");
		message->exec();
	}
	else if(signup==DIFFERENT_REPWD){
		MessageDialog* message=new MessageDialog(this);
		message->setText("different repwd");
		message->exec();
	}
	else if(signup==SUCCESS_SIGNUP){
		MessageDialog* message=new MessageDialog(this);
		message->setText("success signup");
		message->exec();

		this->close();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////

enterdialog::enterdialog(TEAM _team, QWidget *parent)
	: QDialog(parent)
{	
	loginwidget=static_cast<LoginWidget*>(parent);
	team=_team;

	IDLine = new QLineEdit();
	IDLine->setEchoMode(QLineEdit::Normal);
	IDLine->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_]+"), this ));
	IDLine->setFixedSize(180,25);
	pwdLine = new QLineEdit();
	pwdLine->setEchoMode(QLineEdit::Password);
	pwdLine->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0-9_]+"), this ));
	pwdLine->setFixedSize(180,25);
	QHBoxLayout *IDBox= new QHBoxLayout;
	IDBox->addWidget(new QLabel("ID"));
	IDBox->addWidget(IDLine);
	QHBoxLayout *pwdBox= new QHBoxLayout;
	pwdBox->addWidget(new QLabel("pwd"));
	pwdBox->addWidget(pwdLine);
	

	QPushButton* okay=new QPushButton("okay",this);
	QObject::connect(okay, SIGNAL(clicked()), this, SLOT(okay()));

	QPushButton* cancel=new QPushButton("cancel",this);
	QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *buttonBox= new QHBoxLayout;
	buttonBox->addWidget(okay);
	buttonBox->addWidget(cancel);

	QVBoxLayout *VBox=new QVBoxLayout;
	VBox->addLayout(IDBox);
	VBox->addLayout(pwdBox);
	VBox->addLayout(buttonBox);

	setLayout(VBox);
	this->setFixedSize(250,150);

}
void enterdialog::okay(){
	string id=IDLine->text().toStdString();
	string pwd=pwdLine->text().toStdString();

	int enter = loginwidget->getLogin()->enter(id,pwd,team);
	if(enter==NOEXISTING_ID){
		MessageDialog* message=new MessageDialog(this);
		message->setText("noexisting_id");
		message->exec();
	}
	else if(enter==SAME_ID){
		MessageDialog* message=new MessageDialog(this);
		message->setText("same_id");
		message->exec();
	}
	else if(enter==DIFFERENT_PWD){
		MessageDialog* message=new MessageDialog(this);
		message->setText("diffrent_pwd");
		message->exec();
	}
	else if(enter==SUCCESS_ENTER){
		MessageDialog* message=new MessageDialog(this);
		message->setText("success enter");
		message->exec();

		this->accept();
	}
}