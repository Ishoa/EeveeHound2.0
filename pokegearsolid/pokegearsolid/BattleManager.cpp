#pragma once
#include "BattleManager.h"


void causeEffect(Pokemon a_effected, Effect a_effect);


void resolveMove(Pokemon& a_user, Pokemon& a_enemy, int a_move);


battleManager::battleManager() {

}


battleManager::~battleManager() {

}


void battleManager::Init(ResourceManager* resMan) {
	mBattle.Init(resMan);
	pikachu.init(L"Solid Chu");
	enemy.init(L"Solid Chu");
	playermove = 0;
	enemymove = 0;
	curBattleState = BATTLESTART;
	nextBattleState = BATTLESTART;
	donePlayerAttack = false;
	doneEnemyAttack = false;
	battleover = false;
	playerlost = false;
	musicMute = false;
	ltime = GetTickCount();
	curTime = ltime;
	waittime = 0;
}


void battleManager::Update(char keyboard[],DIMOUSESTATE2& mouse, bool& menuPushed, gameState& curState, SoundFrame& soundSys, Menu& menuSys) {///////////////////////////////////////////////////////// FINISH THIS
	curTime = GetTickCount();
	if(curTime-ltime >= 1000.0f)
	{
		ltime = curTime;
		++waittime;
	}
	int tempInt = 0;
	
	if(pikachu.getCurHP() <=0) {
		curBattleState = RESOLVEMOVES;

	}

	switch(curBattleState) {
	case BATTLESTART:
		randomizeEnemy();
		mBattle.menuReset(pikachu,enemy);
		curBattleState = MAIN;
		break;
	case MAIN:
		if((mouse.rgbButtons[0]&0x80)||(keyboard[DIK_RETURN]&0x80)) {
			if(mBattle.getBattleMenu().getPushed(tempInt,menuPushed)) {
				switch(tempInt) {
				case 0: // Fight
					curBattleState = MOVES;
					mBattle.menuResetWithMoves(pikachu,enemy);
					break;
				case 1: // Bag

					break;
				case 2: // Pokemon

					break;
				case 3: // Run

					break;
				}
			}
		}
		break;
	case MOVES:
		if((mouse.rgbButtons[0]&0x80)||(keyboard[DIK_RETURN]&0x80)) {
			if(mBattle.getBattleMenu().getPushed(tempInt,menuPushed)) {
				if(pikachu.getMove(tempInt).getCurPP() > 0) {
					setPlayerMove(tempInt);
					decrementPikaPP(tempInt);
					mBattle.menuResetWithMoves(pikachu,enemy);
					waittime = 0;
					curBattleState = WAIT;
				}
				else {

				}
			}
		}
		break;
	case WAIT:
		if(keyboard[DIK_RETURN]&0x80 && waittime >= 1) {
			waittime = 4;
		}
		if(waittime >= 4 && !battleover) {
			if(donePlayerAttack && doneEnemyAttack) {
				waittime = 0;
				mBattle.menuReset(pikachu, enemy);
				curBattleState = MAIN;
				donePlayerAttack = false;
				doneEnemyAttack = false;
			}
			else {
				waittime = 0;
				curBattleState = RESOLVEMOVES;
			}
		}
		else if(waittime >= 4 && battleover) {
			curBattleState = BATTLESTART;
			curState = stealth;
			soundSys.PlayStream(2,true);
			soundSys.PlayStream(1,musicMute);
			donePlayerAttack = false;
			doneEnemyAttack = false;
			battleover = false;
		}
		break;
	case RESOLVEMOVES:
		if(pikachu.getCurHP() <=0) {
			playerlost = true;
			curBattleState = BATTLESTART;
			curState = GameOver;
			soundSys.PlayStream(2,true);
			soundSys.PlayStream(1,musicMute);
			menuSys.setQuitMenu();
			initPikachu();
			donePlayerAttack = false;
			doneEnemyAttack = false;
			battleover = false;
		}
		else if(pikachu.getSpeed() >= enemy.getSpeed() && !donePlayerAttack || doneEnemyAttack && !donePlayerAttack || pikachu.getMove(playermove).getPriority() == 1 && !donePlayerAttack) {
			resolveMoveInOrder(true);
			donePlayerAttack = true;
			mBattle.menuResetWithMoves(pikachu, enemy);
			mBattle.addText(pikachu,pikachu.getMove(playermove));
		}
		else if(enemy.getCurHP() > 0){
			int randomenemymove = rand()%4;
			setEnemyMove(randomenemymove);
			decrementEnemyPP(randomenemymove);
			resolveMoveInOrder(false);
			doneEnemyAttack = true;
			mBattle.menuResetWithMoves(pikachu, enemy);
			mBattle.addText(enemy,enemy.getMove(enemymove));
		}
		else {
			doneEnemyAttack = false;
			donePlayerAttack = false;
			battleover = true;
		}
		if(battleover)
			curBattleState = OVER;
		else
			curBattleState = WAIT;
		break;
	case OVER:
		waittime = 0;
		mBattle.addYouWin();
		curBattleState = WAIT;
		break;
	}
	mBattle.Update(keyboard,mouse,menuPushed);
}


void battleManager::Render(gameState& curstate, renderInfo sprites[],int& NumSprit,TextStruct text[],int& NumText) {
	mBattle.GetBattleRender(sprites,NumSprit,text,NumText,enemy.getSpecies());
	switch(curBattleState) {
	case BATTLESTART:

		break;
	case MAIN:
		
		break;
	case MOVES:
		
		break;
	case WAIT:
		
		break;
	case RESOLVEMOVES:
		
		break;
	case OVER:
		
		break;
	}
}


void battleManager::setPikachu(Pokemon a_pikachu) {
	pikachu = a_pikachu;
}


void battleManager::setEnemy(Pokemon a_enemy) {
	enemy = a_enemy;
}


Pokemon battleManager::getPikachu() {
	return pikachu;
}


Pokemon battleManager::getEnemy() {
	return enemy;
}


void battleManager::decrementPikaPP(int a_move) {
	pikachu.decrementPP(a_move);
}


void battleManager::decrementEnemyPP(int a_move) {
	enemy.decrementPP(a_move);
}


void battleManager::randomizeEnemy() {
	int random = rand()%4;
	if(random == 0)
		enemy.init(L"RATATA");
	else if(random == 1)
		enemy.init(L"ZUBAT");
	else if(random == 2)
		enemy.init(L"KOFFING");
	else if(random == 3)
		enemy.init(L"EKANS");
}


void battleManager::initPikachu() {
	pikachu.init(L"Solid Chu");
}


void battleManager::resolveMoveInOrder(bool a_user) {
	if(a_user) {
		resolveMove(pikachu, enemy, playermove);
	}
	else
		resolveMove(enemy, pikachu, enemymove);
}


void battleManager::setPlayerMove(int a_move) {
	playermove = a_move;
}



int battleManager::getPlayerMove() {
	return playermove;
}


void battleManager::setEnemyMove(int a_move) {
	enemymove = a_move;
}


int battleManager::getEnemyMove() {
	return enemymove;
}


void causeEffect(Pokemon a_effected, Effect a_effect) {
	if(a_effect == BURN) {
		a_effected.setStatus(true,0);
	}
	else if(a_effect == SLEEP) {
		a_effected.setStatus(true,1);
	}
	else if(a_effect == PARALYSIS) {
		a_effected.setStatus(true,2);
	}
	else if(a_effect == POISONED) {
		a_effected.setStatus(true,3);
	}
	else if(a_effect == FROZEN) {
		a_effected.setStatus(true,4);
	}
	else if(a_effect == CONFUSION) {
		a_effected.setStatus(true,5);
	}
	else if(a_effect == INCREASEATTACK) {
		a_effected.setStatChanges(1,0);
	}
	else if(a_effect == INCREASEDEFENSE) {
		a_effected.setStatChanges(1,1);
	}
	else if(a_effect == INCREASESPECATTACK) {
		a_effected.setStatChanges(1,2);
	}
	else if(a_effect == INCREASESPECDEFENSE) {
		a_effected.setStatChanges(1,3);
	}
	else if(a_effect == INCREASESPEED) {
		a_effected.setStatChanges(1,4);
	}
	else if(a_effect == DECREASEATTACK) {
		a_effected.setStatChanges(-1,0);
	}
	else if(a_effect == DECREASEDEFENSE) {
		a_effected.setStatChanges(-1,1);
	}
	else if(a_effect == DECREASESPECATTACK) {
		a_effected.setStatChanges(-1,2);
	}
	else if(a_effect == DECREASESPECDEFENSE) {
		a_effected.setStatChanges(-1,3);
	}
	else if(a_effect == DECREASESPEED) {
		a_effected.setStatChanges(-1,4);
	}
};


void resolveMove(Pokemon& a_user, Pokemon& a_enemy, int a_move) {
	int tempdamage;
	int random = rand()%100;
	bool hitormiss = true;
	if(random > a_user.getMove(a_move).getAccuracy())// Checks if it hits or misses, true for hit, false for miss
		hitormiss = false;
	if(hitormiss) {
		if(a_user.getMove(a_move).getWhichStat() == 0) // Checks to see which stat the move needs, 0 for Attack, 1 for Spec Attack, 2 for no stat
			tempdamage = a_user.getMove(a_move).getDamage()+a_user.getAttack()/5 - a_enemy.getDefense()/5;
		else if(a_user.getMove(a_move).getWhichStat() == 1) 
			tempdamage = a_user.getMove(a_move).getDamage()+a_user.getSpecAtt()/5 - a_enemy.getSpecDef()/5;
		else
			tempdamage = 0;
		if(a_user.getType() == a_user.getMove(a_move).getType()) // STAB
			tempdamage *=1.5;
		if(tempdamage >= a_enemy.getCurHP()) // If it sets the target's health below 0, it just sets it to 0.
			a_enemy.setCurHP(0);
		else
			a_enemy.setCurHP(a_enemy.getCurHP()-tempdamage);
		if(a_user.getMove(a_move).hasEffect()) {// Checks if it causes a status effect
			random = rand()%100;
			if(random <= a_user.getMove(a_move).getChanceEffect()) {// Checks if the status effect happens, 
				if(a_user.getMove(a_move).getTarget())
					causeEffect(a_user, a_user.getMove(a_move).getEffect());
				else
					causeEffect(a_enemy, a_user.getMove(a_move).getEffect());
			}

		}
		if(a_user.getMove(a_move).getName() == L"Self-Destruct")
			a_user.setCurHP(0);
	}
		
};