#include "itemlist.h"

Item* ItemList::ip(const int id) {
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