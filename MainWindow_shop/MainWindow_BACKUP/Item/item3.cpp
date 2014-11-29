#include "item3.h"

using namespace std;

Item3::Item3() { 
	name="시간절반";
	desc="한 턴 동안 상대방의 제한 시간을 반으로 줄인다.";
	ID=3;
	price=1000;
	time=1;
	image="Resources/item3.jpg";
}

bool Item3::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}
