#pragma once
#include <vector>
#include "Menu.h"
#include "Defines.h"
#include "Pokemon.h"
#include "Button.h"
#include <ctime>
#include "Battle.h"
#include "SoundFrame.h"




enum BattleState {
	BATTLESTART,
	MAIN,
	MOVES,
	WAIT,
	RESOLVEMOVES,
	OVER
};


class battleManager {
private:
	Battle mBattle;
	Pokemon pikachu;
	Pokemon enemy;
	int playermove,enemymove;
	BattleState curBattleState, nextBattleState;
	bool donePlayerAttack;
	bool doneEnemyAttack;
	bool battleover;
	bool playerlost;
	bool musicMute;
	int curTime, waittime, ltime;
public:
	battleManager();
	~battleManager();
	void Init(ResourceManager* resMan);
	void Update(char keyboard[],DIMOUSESTATE2& mouse,bool& menuPushed, gameState& curState, SoundFrame& soundSys, Menu& menuSys);
	void Render(gameState& curstate, renderInfo sprites[],int& NumSprit,TextStruct text[],int& NumText);

	//Older things
	void setPikachu(Pokemon);
	void setEnemy(Pokemon);
	Pokemon getPikachu();
	Pokemon getEnemy();
	void decrementPikaPP(int);
	void decrementEnemyPP(int);
	void randomizeEnemy();
	void initPikachu();
	void resolveMoveInOrder(bool);
	void setPlayerMove(int);
	int getPlayerMove();
	void setEnemyMove(int);
	int getEnemyMove();
};