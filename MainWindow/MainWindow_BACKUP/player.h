#include <iostream>
#include "global.h"
using namespace std;
#ifndef Player_h
#define Player_h

class Player
{
private:
	string id;
	string pwd;
	int win;
	int lose;
	int money;
	int* item;
public:
	Player();
	~Player();
	void setPlayer(string,string,int,int,int,int*);
	void setItem(int*);
	void setMoney(int);
	void incWin();
	void incLose();
	Player& operator=(Player&); 
	string getID();
	int* getItem();
	int getMoney();

	void save();
};

#endif