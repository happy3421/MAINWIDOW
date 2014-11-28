#include "Login.h"
#include <fstream>
#include <iostream>
#include <string>
#include <io.h>
using namespace std;
Login::Login(){
	player= new Player*[2];
	player[0]= new Player;
	player[1]= new Player;
}
Login::~Login(){
	delete player[0];
	delete player[1];
	delete[] player;
}
SIGNUP Login::signUp(string id, string pwd, string repwd)
{
	int win=0;
	int lose=0;
	int money=2000;
	int item[ITEMTYPE_NUM]={0};
	
	string filename="Users/";
	filename.append(id);
	filename.append(".txt");
	
	if( access(filename.c_str(),0)==0 )
		return EXISTING_ID;
	else if(id.length()==0)	//spa
		return NO_ID;
	else if(pwd.length()==0)
		return NO_PWD;
	else if(pwd != repwd)
		return DIFFERENT_REPWD;
	else{
		ofstream userfile(filename);
		
		userfile << id <<endl;
		userfile << pwd <<endl;
		userfile << win <<endl;
		userfile << lose<<endl;
		userfile << money <<endl;
		for(int i=0; i<ITEMTYPE_NUM; i++)
			userfile << item[i] <<endl;
		
		userfile.close();
		return SUCCESS_SIGNUP;
	}
}
ENTER Login::enter(string _id, string _pwd, TEAM _team)
{
	string id;
	string pwd;
	int money;
	int win;
	int lose;
	int item[ITEMTYPE_NUM];
	int team=static_cast<int>(_team);

	string filename="Users/";
	filename.append(_id);
	filename.append(".txt");

	ifstream userfile(filename);
	if(!userfile)
		return NOEXISTING_ID;
	else if (player[(1-team)]->getID()==_id)
		return SAME_ID;
	else{
		userfile>>id>>pwd>>win>>lose>>money;
		if(pwd != _pwd)
			return DIFFERENT_PWD;
		else{
			for(int i=0; i<ITEMTYPE_NUM; i++)
				userfile>>item[i];
			player[team]->setPlayer(id,pwd,win,lose,money,item);
			return SUCCESS_ENTER;
		}
	}
}

Player** Login::getPlayer(){
	return player;
}