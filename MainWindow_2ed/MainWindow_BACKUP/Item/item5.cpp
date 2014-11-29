#include "item5.h"

using namespace std;

Item5::Item5() { 
	name="골드두배";
	desc="게임이 종료될 때 획득하는 골드의 양을 두 배로 늘린다";
	ID=5;
	price=1000;
	time=0;
}

bool Item5::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}