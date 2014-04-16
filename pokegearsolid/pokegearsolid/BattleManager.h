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
	BattleState curBattleState;
	bool donePlayerAttack;
	bool doneEnemyAttack;
	bool battleover;
	bool playerlost;
	bool musicMute;
	int curTime, waittime, ltime;
public:
	battleManager();
	~battleManager();
	void Init(TextureStruc a_sprites[], int a_sprit);
	void Update(char keyboard[],DIMOUSESTATE2& mouse, renderInfo sprites[],int& NumSprit,TextStruct text[],int& NumText, bool& menuPushed, gameState& curState, SoundFrame& soundSys, Menu& menuSys);
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