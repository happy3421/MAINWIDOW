#include "item2.h"

using namespace std;

Item2::Item2() { 
	name="아이템 삭제";
	desc="상대방이 보유한 아이템 중 하나를 무작위로 삭제시킨다.";
	ID=2;
	price=1000;
	time=0;
	image="Resources/item2.jpg";
}

bool Item2::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}

