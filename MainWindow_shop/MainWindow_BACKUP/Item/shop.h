#ifndef SHOP_H
#define SHOP_H

#include "itemlist.h"
#include "../global.h"
#include "../player.h"

using namespace std;

class Shop:public ItemList {
private:
	Player *player;
public:
	Shop(Player*);
	bool buyItem(const int, const int);
	bool sellItem(const int, const int);
	int equipItem(const int);
	int removeItem(const int slot);
};

#endif
