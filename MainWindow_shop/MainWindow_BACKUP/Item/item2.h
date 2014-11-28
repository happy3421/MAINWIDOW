#ifndef ITEM2_H
#define ITEM2_H

#include "item.h"

using namespace std;

class Item2:public Item {
public:
	Item2();
	virtual bool itemGame(Board*, int);
};

#endif
