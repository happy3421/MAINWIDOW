#include "item4.h"

using namespace std;

Item4::Item4() { 
	name="시간두배";
	desc="한 턴 동안 자신의 제한 시간을 두 배로 늘린다.";
	ID=4;
	price=1000;
	time=1;
	image="Resources/item4.jpg";
}

bool Item4::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}