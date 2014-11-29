#include "dialog.h"

MessageDialog::MessageDialog(QWidget* parent)
	:QDialog(parent)
{	
	this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	messageButton= new QPushButton(this);
	messageButton->resize(300,50);	//default size
	connect(messageButton, SIGNAL(clicked()), this, SLOT(close()));
}
void MessageDialog::setText(const QString &str){
	messageButton->setText(str);
}
void MessageDialog::resize(int w, int h){
	messageButton->resize(w,h);
}
void MessageDialog::setStyleSheet(const QString& stylesheet){
	messageButton->setStyleSheet(stylesheet);
}
//////////////////////////////////////////////////////////////////////////////
DecisionDialog::DecisionDialog(QWidget* parent)
	:QDialog(parent)
{	
	this->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
	messageLabel= new QLabel(this);
	acceptButton= new QPushButton("OK",this);
	connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
	rejectButton= new QPushButton("Cancel",this);
	connect(rejectButton, SIGNAL(clicked()), this, SLOT(reject()));

	QHBoxLayout *HBox1= new QHBoxLayout;
	HBox1->addWidget(messageLabel);
	QHBoxLayout *HBox2= new QHBoxLayout;
	HBox2->addWidget(acceptButton);
	HBox2->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
	HBox2->addWidget(rejectButton);
	QVBoxLayout *VBox=new QVBoxLayout;
	VBox->addLayout(HBox1);
	VBox->addLayout(HBox2);
	
	setLayout(VBox);
}

void DecisionDialog::setText(const QString &str){
	messageLabel->setText(str);
	messageLabel->setAlignment(Qt::AlignHCenter);
	this->setFixedSize(this->sizeHint().width(),this->sizeHint().height());
}