#include <global.h>
#include <iostream>
#include <fstream>
#include "Player.h"

#ifndef Login_h
#define Login_h

class Login
{
public:
	Login();
	~Login();
	SIGNUP signUp(string, string, string);
	ENTER enter(string, string, TEAM);
	Player** getPlayer();
private:
	Player** player;
};

#endif
