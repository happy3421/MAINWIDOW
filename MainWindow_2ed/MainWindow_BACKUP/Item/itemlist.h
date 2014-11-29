#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item1.h"
#include "item2.h"
#include "item3.h"
#include "item4.h"
#include "item5.h"
#include "item6.h"

using namespace std;

class ItemList {
private:
	Item1 item1;
	Item2 item2;
	Item3 item3;
	Item4 item4;
	Item5 item5;
	Item6 item6;
public:
	Item* ip(const int);
};

#endif
