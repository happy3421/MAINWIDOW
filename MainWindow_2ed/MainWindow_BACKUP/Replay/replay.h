#pragma once
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include "player.h"

class Record{
private:
	Player* record_playerone;
	Player* record_playertwo;
	int P1Win; 
	int P1Lose;
	int P2Win;
	int P2Lose;
	int howMany;
	int** timeRecord;
	int fileExist;
public:
	void showRecord(Player*, Player*);
	int getP1Win();
	int getP2Win();
	int getfileExist();
	int gethowMany();
	int** gettimeRecord();
};

class Replay: public Record{
private:
	int whoWin;
	int P1Win;
	int P2Win;
	int howMany;
	int** timeRecord;
	TEAM ongoingTeam;
	TEAM firstTurn;
	int** CellStr;
	ifstream playing;
public:
	Replay();
	int getCellStr(int, int);
	int checkEnd();
	void closing();
	void showReplay();
	void getInfo(Player*, Player*);
//	void saveBoard(Cell**, Player*, Player*);
	void saveRecord(Player*, Player*);
};