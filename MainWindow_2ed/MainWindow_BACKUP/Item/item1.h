#ifndef ITEM1_H
#define ITEM1_H

#include "item.h"

using namespace std;

class Item1:public Item {
public:
	Item1();
	virtual bool itemGame(Board*, int);
};

#endif
