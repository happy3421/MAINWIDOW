#include "Replay.h"
#include <io.h>
using namespace std;

Replay::Replay(){
	P1Win = 0;
	P2Win = 0;
	firstTurn = ATEAM;
	CellStr = new int*[9];
	for(int i=0;i<9;i++)
		CellStr[i] = new int[9];
}

int Record::getP1Win(){
	return P1Win;
}

int Record::getP2Win(){
	return P2Win;
}

int Record::getfileExist(){
	return fileExist;
}

void Record::showRecord(Player* playerOne, Player* playerTwo){
	string filename;
	filename = "Users/";
	if(playerOne->getID().compare(playerTwo->getID())<0){
		filename += playerOne->getID();
		filename += "_";
		filename += playerTwo->getID();
	}
	else{
		filename += playerTwo->getID();
		filename += "_";
		filename += playerOne->getID();
	}
	filename += ".txt";
	fileExist = access(filename.c_str(), 0);
	if(fileExist == 0){
		ifstream playing(filename);
		if(playerOne->getID().compare(playerTwo->getID())<0){
			playing>>P1Win;
			playing>>P2Win;
		}
		else{
			playing>>P2Win;
			playing>>P1Win;
		}
		P1Lose = P2Win;
		P2Lose = P1Win;
		playing>>howMany;
		timeRecord = new int*[howMany];
		for(int i = 0;i<howMany;i++){
			timeRecord[i]= new int[6];
		}
		for(int i=0;i<howMany;i++){
			for(int j=0;j<6;j++)
				playing>>timeRecord[i][j];
		}
	}
}

void Replay::getInfo(Player* playerOne, Player* playerTwo){
	string filename;
	filename = "Users/";
	if(playerOne->getID().compare(playerTwo->getID())<0){
		filename += playerOne->getID();
		filename += "_";
		filename += playerTwo->getID();
	}
	else{
		filename += playerTwo->getID();
		filename += "_";
		filename += playerOne->getID();
	}
	filename += ".txt";
	playing.open(filename.c_str());
	if(playerOne->getID().compare(playerTwo->getID())<0){
		playing>>P1Win;
		playing>>P2Win;
	}
	else{
		playing>>P2Win;
		playing>>P1Win;
	}
	playing>>howMany;
	timeRecord = new int*[howMany];
	for(int i = 0;i<howMany;i++){
		timeRecord[i]= new int[6];
	}
	for(int i=0;i<howMany;i++){
		for(int j=0;j<6;j++)
			playing>>timeRecord[i][j];
	}
}

int Replay::getCellStr(int i, int j){
	return CellStr[i][j];
}

int Replay::checkEnd(){
	int check = playing.eof();
	return check;
}

int Record::gethowMany(){
	return howMany;
}

int** Record::gettimeRecord(){
	return timeRecord;
}

void Replay::closing(){
	playing.close();
}

void Replay::showReplay(){
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			CellStr[i][j]=-1;
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			playing>>CellStr[i][j];
		}
	}
}
void Replay::saveRecord(Player* playerOne, Player* playerTwo){
	string filename;
	char removefile[100];
	int P1Win, P2Win;
	int P1Winnum, P2Winnum;
	filename = "Users/";
	if(playerOne->getID().compare(playerTwo->getID())<0){
		filename += playerOne->getID();
		filename += "_";
		filename += playerTwo->getID();
	}
	else{
		filename += playerTwo->getID();
		filename += "_";
		filename += playerOne->getID();
	}
	filename += ".txt";
	ifstream playing(filename);
	playing>>P1Win;
	playing>>P2Win;
	playing>>howMany;
	timeRecord = new int*[howMany];
	for(int i = 0;i<howMany;i++){
		timeRecord[i]= new int[6];
	}
	for(int i=0;i<howMany;i++){
		for(int j=0;j<6;j++)
			playing>>timeRecord[i][j];
	}
	while(!playing.eof())
		playing>>whoWin;
	playing.close();
	string func = "erase ";
	string command;
	command = func + filename;
	system(command.c_str());
	ofstream saveCell(filename);
	if(whoWin==0)
		P1Win += 1;
	else
		P2Win += 1;
	saveCell << P1Win<<"\n";
	saveCell << P2Win<<"\n";
	saveCell << howMany+1 <<"\n";
	for(int i=0;i<howMany;i++){
		for(int j=0;j<6;j++)
			saveCell << timeRecord[i][j]<<" ";
		saveCell<<"\n";
	}
	time_t time1;
	struct tm* time2;
	time(&time1);
	time2 = localtime(&time1);
	saveCell<< time2->tm_year+1900<<" ";
	saveCell<< time2->tm_mon+1<<" ";
	saveCell<< time2->tm_mday<<" ";
	saveCell<< time2->tm_hour<<" ";
	saveCell<< time2->tm_min<<" ";
	saveCell<< whoWin;
	saveCell.close();
}/*
void Replay::saveBoard(Cell** replay_board, Player* playerOne, Player* playerTwo){
	string filename;
	char P1Win, P2Win, firstTeam;
	firstTeam = (char) firstTurn;
	if(playerOne->getID().compare(playerTwo->getID())<0){
		filename = playerOne->getID();
		filename += "_";
		filename += playerTwo->getID();
	}
	else{
		filename = playerTwo->getID();
		filename += "_";
		filename += playerOne->getID();
	}
	filename += ".txt";
	fstream saveCell;
	saveCell.open(filename, ios::app);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			saveCell << replay_board[i][j].getCharNum()<<" ";	//cell이 본인의 말을 나타내는 숫자를 갖게
		}
		saveCell<<"\n";
	}
	saveCell.close();
}*/