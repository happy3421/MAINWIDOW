#ifndef SHOP_H
#define SHOP_H

#include "item1.h"
#include "item2.h"
#include "item3.h"
#include "item4.h"
#include "item5.h"
#include "item6.h"
#include "../global.h"
#include "../player.h"

using namespace std;

class Shop {
private:
	Item1 item1;
	Item2 item2;
	Item3 item3;
	Item4 item4;
	Item5 item5;
	Item6 item6;
	Player *player;
public:
	Item* ip(const int);
	Shop(Player*);
	void buyItem(const int, const int);
	void sellItem(const int, const int);
};

#endif
