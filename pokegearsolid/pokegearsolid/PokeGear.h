#pragma once

#include "DirectXFrame.h"
#include "dxinput.h"
#include "Map.h"
#include "Stealth.h"
#include "PlayerState.h"
#include "Menu.h"
#include "SoundFrame.h"
#include "Battle.h"
#include "Dio.h"
#include "ResourceManager.h"

#define max3d 100
#define max2d 100
#define maxtext 100


//TODO: move to the resource manager
#define maxtexture 20
#define maxModels 20
#define maxMat 10


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

enum battleState {
	BATTLESTART,
	MAIN,
	MOVES,
	WAIT,
	RESOLVEMOVES,
	OVER
};

class PokeGear
{
private:
	ResourceManager resMan;
	gameState curState;
	battleState curBattleState;
	dxinputframe input;
	DirectXFrame display;
	char keyboard [256];
	DIMOUSESTATE2 mouse;
	//camera for render
	cam camera;
	//3D objects for render
	D3Object D3Objs[max3d];

	//TODO: move to resource manager
	D3Object Models[maxModels];

	//2D objects for render
	renderInfo Sprites[max2d];
	//Mouse cursor sprite
	renderInfo curSpri;
	//Text for render
	TextStruct Text[maxtext];
	
	//TODO: move to resource manager
	TextureStruc textures[maxtexture];
	D3DMATERIAL9 materials[maxMat];
	
	PlayerState curPlay;
	Stealth sneak;
	Menu menuSys;
	SoundFrame soundSys;
	bool bCanInput;
	bool bCanInput2;
	bool menuPushed;
	char scenenumber;
	bool newscene;
	bool musicMute;
	Battle battler;
	bool donePlayerAttack;
	bool doneEnemyAttack;
	bool battleover;
	bool playerlost;
	Dio talks;
public:
	PokeGear();
	void init(HWND& hWnd, HINSTANCE& hInst, bool bWindowed);
	void update();
	void shutdown();
	~PokeGear();
};