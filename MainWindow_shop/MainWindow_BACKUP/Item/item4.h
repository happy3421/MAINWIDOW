#ifndef ITEM4_H
#define ITEM4_H

#include "item.h"

using namespace std;

class Item4:public Item {
public:
	Item4();
	virtual bool itemGame(Board*, int);
};

#endif
