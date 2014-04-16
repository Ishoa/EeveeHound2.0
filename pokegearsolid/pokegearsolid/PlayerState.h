#pragma once
#include "Defines.h"
#include "Pokemon.h"

#include <vector>

class PlayerState
{
private:
	Pos curPos,rendPos;
	LPCWSTR curMapName;
	std::vector<bool> watchedDialogs;
public:
	PlayerState();
	Pos getPos();
	Pos getRen();
	void setWatched(int);
	void setPos(int locx,int locy,int renx,int reny);
	bool setSceen(bool[],int arraySize);
	bool sceenNew(int);
	LPCWSTR getMap();
};