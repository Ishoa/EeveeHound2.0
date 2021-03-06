#include "PlayerState.h"
//number of sceens for story
#define numberSceens 2


PlayerState::PlayerState()
{
	bool setSceen = false;

	curPos.X = 0;
	curPos.Y = 0;
	curPos.Z = 0;

	rendPos.X = 1;
	rendPos.Y = 1;
	rendPos.Z = 0;

	for(int i = 0;i<numberSceens;++i)
	{
		watchedDialogs.push_back(setSceen);
	}
}



bool PlayerState::setSceen(bool states[],int arraySize)
{
	int length;
	
	if(arraySize<numberSceens)
	{
		length = arraySize;
	}
	else
	{
		length = numberSceens;
	}

	for(int i = 0;i<length;++i)
	{
		watchedDialogs[i] = states[i];
	}

	if(arraySize>numberSceens)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Pos PlayerState::getPos()
{
	return curPos;
}

Pos PlayerState::getRen()
{
	return rendPos;
}

void PlayerState::setPos(int locx,int locy,int renx,int reny)
{
	curPos.X = locx;
	curPos.Y = locy;
	curPos.Z = 0;

	rendPos.X = renx;
	rendPos.Y = reny;
	rendPos.Z = -2.0f;
}


bool PlayerState::sceenNew(int num)
{
	if(num<watchedDialogs.size())
	{
		return !watchedDialogs[num];
	}
	return false;
}

void PlayerState::setWatched(int num)
{
	watchedDialogs[num] = true;
}