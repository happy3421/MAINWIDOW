#ifndef ITEM6_H
#define ITEM6_H

#include "item.h"

using namespace std;

class Item6:public Item {
public:
	Item6();
	virtual bool itemGame(Board*, int);
};

#endif
