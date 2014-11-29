#ifndef ITEM3_H
#define ITEM3_H

#include "item.h"

using namespace std;

class Item3:public Item {
public:
	Item3();
	virtual bool itemGame(Board*, int);
};

#endif
