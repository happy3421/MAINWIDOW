#ifndef ITEM5_H
#define ITEM5_H

#include "item.h"

using namespace std;

class Item5:public Item {
public:
	Item5();
	virtual bool itemGame(Board*, int);
};

#endif

