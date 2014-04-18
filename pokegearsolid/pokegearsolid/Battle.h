// battle system by josh
// I made changes to Battle
// Menu
// PokeGear
// Pokemon
// PlayerState
// DirectXFrame
// And possibly other things I'm forgetting




#pragma once
#include <vector>
#include "Menu.h"
#include "Defines.h"
#include "Pokemon.h"
#include "Button.h"
#include <ctime>
#include "ResourceManager.h"
#define numsprites 100
#define numbattletext 100

enum gameState
{
	MainMenu,
	stealth,
	story,
	battle,
	GameOver,
	victory,// Balls to the wall I'm putting some states here
	options,
	credits
};


class Battle {
private:
	Menu battlemenu;
	renderInfo sprites[numsprites];
	int curnumsprites;
	TextStruct battletext[numbattletext];
	int curtextincrement;
	wchar_t charactertempthingy[32][16];
	
public:
	Battle();
	~Battle();
	Battle(Menu a_battlemenu, int a_numsprites, renderInfo* a_sprites);
	void Init(ResourceManager* resMan);
	void battleStart(Pokemon, Pokemon);
	void addText(Pokemon, Move);
	void addYouWin();
	void menuReset(Pokemon, Pokemon);
	void menuResetWithMoves(Pokemon, Pokemon);
	void setBattleMenu(Menu a_battlemenu);
	Menu getBattleMenu();
	void addSprite(renderInfo a_newsprite);
	renderInfo getSprite(int a_index);
	int getCurNumSprites();
	void incrementCurNumSprites();
	void GetBattleRender(renderInfo[],int& numSprite,TextStruct[],int& numText, Species a_species);
	void Update(char keyboard[],DIMOUSESTATE2& mouse,bool &pushed);
};


