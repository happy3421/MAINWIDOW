#include "shop.h"

using namespace std;

Shop::Shop(Player* _player) {
	player=_player;
}

bool Shop::buyItem(const int id, const int num) {
	if(id<0 || id>ITEMTYPE_NUM)
		return 0;
	int price=ip(id)->getPrice();
	int money=player->getMoney()-price*num;
	if(money>=0) {
		player->setMoney(money);
		player->getItem()[id]+=num;
		return 1;
	}
	else
		return 0;
}

bool Shop::sellItem(const int id, const int num) {
	if(id<0 || id>ITEMTYPE_NUM)
		return 0;
	int price=ip(id)->getPrice();
	int money=player->getMoney()+price*num;
	if(money>=0) {
		player->setMoney(money);
		player->getItem()[id]-=num;
		return 1;
	}
	else
		return 0;
}

int Shop::equipItem(const int id) {
	if(id<0 || id>ITEMTYPE_NUM)
		return -1;
	if(player->getItem()[id]==0 )
		return -1;
	for(int i=0; i<3; i++) {
		if(player->getItemE(i)<0) {
			player->setItemE(i,id);
			player->getItem()[id]--;
			return i;
		}
	}
}

int Shop::removeItem(const int slot) {
	int id=player->getItemE(slot);
	if(id==-1)
		return -1;
	else {
		player->setItemE(slot,-1);
		player->getItem()[id]++;
		return id;
	}
}
