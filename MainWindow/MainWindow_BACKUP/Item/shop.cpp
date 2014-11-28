#include "shop.h"

using namespace std;

Shop::Shop(Player* _player) {
	player=_player;
}

Item* Shop::ip(const int id) {
	if(id==0)
		return &item1;
	else if(id==1)
		return &item2;
	else if(id==2)
		return &item3;
	else if(id==3)
		return &item4;
	else if(id==4)
		return &item5;
	else if(id==5)
		return &item6;
	else
		return NULL;
}

void Shop::buyItem(const int id, const int num) {
	if(id<0 || id>ITEMTYPE_NUM)
		return;
	int price=ip(id)->getPrice();
	int money=player->getMoney()-price*num;
	if(money>=0) {
		player->setMoney(money);
		player->getItem()[id]+=num;
	}
}

void Shop::sellItem(const int id, const int num) {
	if(id<0 || id>ITEMTYPE_NUM)
		return;
	int price=ip(id)->getPrice();
	int money=player->getMoney()+price*num;
	if(money>=0) {
		player->setMoney(money);
		player->getItem()[id]-=num;
	}
}

