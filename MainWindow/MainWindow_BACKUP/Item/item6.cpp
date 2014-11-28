#include "item6.h"

using namespace std;

Item6::Item6() { 
	name="먼저하기";
	desc="랜덤으로 정해지는 첫 순서를 아이템 사용자에게 넘겨준다";
	ID=6;
	price=1000;
	time=0;
}

bool Item6::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}

