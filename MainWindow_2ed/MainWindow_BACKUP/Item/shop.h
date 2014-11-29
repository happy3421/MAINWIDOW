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
	void buyItem(const int, const int);
	void sellItem(const int, const int);
	int equipItem(const int);
};

#endif
