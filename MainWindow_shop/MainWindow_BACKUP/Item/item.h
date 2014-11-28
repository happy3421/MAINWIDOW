#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "../InGame/Board.h"

using namespace std;

class Item {
protected:
	string name;
	string desc;
	int ID;
	int price;
	int time; //0=Before Game, 1=In Your Turn
	string image;
public:
	string getName();
	string getDesc();
	int getID();
	int getPrice();
	int getTime();
	string getImage();
	virtual bool itemGame(Board*, int)=0; //Get time, run command, then return 1 if succeed
};

#endif
