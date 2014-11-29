#include "item1.h"

using namespace std;

Item1::Item1() { 
	name="Undo";
	desc="Undo your last move.";
	ID=1;
	price=1000;
	time=1;
	image="Resources/item1.jpg";
}

bool Item1::itemGame(Board* board, int _time) {
	if(time != _time)
		return 0;
	else {
		//To Do
	}
}
