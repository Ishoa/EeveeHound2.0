#include "PokeGear.h"

PokeGear::PokeGear()
{
	//cam setup
	camera.cam_up_vec = D3DXVECTOR3(0,1,0);
	camera.cam_pos = D3DXVECTOR3(0,1,-5);
	camera.cam_look_pos = D3DXVECTOR3(0,0,-4);
	bCanInput = true;
	menuPushed = false;
	curState = MainMenu;
	bCanInput2 = true;
	newscene=true;
	musicMute = false;
}

void PokeGear::init(HWND& hWnd, HINSTANCE& hInst, bool bWindowed)
{
	D3DMATERIAL9 tempMat;
	int tex = 0;
	input.init(hWnd,hInst);
	display.Init(hWnd,hInst,bWindowed);
	soundSys.Init();

	resMan.changeLoader(&display);
	//TODO: remove when res is fully intigrated
	for(int i = 0;i<maxModels;++i)
	{
		Models[i].obj = 0;
	}
	for(int i = 0;i<maxtexture;++i)
	{
		textures[i].objTex = 0;
	}
	
	//TODO: change load so it dosnt use materials or textures stored here
	
	//start art loading
	TextureStruc tempTex;
	//Player Mat
	tempMat.Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);		// Ambient color reflected
	tempMat.Diffuse = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);		// Diffuse color reflected
	tempMat.Emissive = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// Emissive color reflected
	tempMat.Specular = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);		// Specular
	tempMat.Power = 0.0f;				// Specular highlight intensity
	
	resMan.addMaterial(L"PlayerMat",tempMat);

	//player Model
	
	display.CreateUVCube(Models[0],1,1,1);
	Models[0].objMat = &materials[0];
	ZeroMemory(&Models[0].matrix,sizeof(Models[0].matrix));
	D3DXMatrixTranslation(&Models[0].matrix,0,0,1);
	

	resMan.addCube(L"PlayerModel",1,1,1,true);
	resMan.setModMat(L"PlayerModel",L"PlayerMat");
	ZeroMemory(&resMan.getModel(L"PlayerModel")->matrix,sizeof(D3DMATRIX));
	D3DXMatrixTranslation(&resMan.getModel(L"PlayerModel")->matrix,0,0,1);
	//default textue
	//display.LoadTex(L"playtex.bmp",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"playtex.bmp");
	textures[tex] = tempTex;
	++tex;
	//player texture
	//display.LoadTex(L"pikachu.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"pikachu.png");
	textures[tex] = tempTex;	 
	resMan.getModel(L"PlayerModel")->objTex = resMan.getTexture(L"pikachu.png")->objTex;	
	++tex;
	//enemy texture
	//display.LoadTex(L"enemy.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"enemy.png");
	textures[tex] = tempTex;
	++tex;
	// BATTLE TEXTURES START
	//battle background texture
	//display.LoadTex(L"battlebackground.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_ARGB(0,0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"battlebackground.png");
	textures[tex] = tempTex;
	++tex;
	//battle pikachu texture
	//display.LoadTex(L"battlepikachu.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_ARGB(0,0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"battlepikachu.png");
	textures[tex] = tempTex;
	++tex;
	//battle ratata texture
	//display.LoadTex(L"battlerattata.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_ARGB(0,0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"battlerattata.png");
	textures[tex] = tempTex;
	++tex;
	//battle zubat texture
	//display.LoadTex(L"battlezubat.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_ARGB(0,0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"battlezubat.png");
	textures[tex] = tempTex;
	++tex;
	//battle koffing texture
	//display.LoadTex(L"battlekoffing.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_ARGB(0,0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"battlekoffing.png");
	textures[tex] = tempTex;
	++tex;
	//battle ekans texture
	//display.LoadTex(L"battleekans.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_ARGB(0,0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"battleekans.png");
	textures[tex] = tempTex;
	++tex;

	//character sprites
	//snake
	//display.LoadTex(L"snake.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"snake.png");
	textures[tex] = tempTex;
	++tex;
	//joy
	//display.LoadTex(L"joy.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"joy.png");
	textures[tex] = tempTex;
	++tex;
	//pikachu
	//display.LoadTex(L"solidchu.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"solidchu.png");
	textures[tex] = tempTex;
	++tex;
	//evilchu
	//display.LoadTex(L"evilchu.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"evilchu.png");
	textures[tex] = tempTex;
	++tex;

	//load more stuff
	//display.LoadTex(L"Pokegearsolid.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"Pokegearsolid.png");
	textures[tex] = tempTex;
	++tex;

	//display.LoadTex(L"deathbyekans.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"deathbyekans.png");
	textures[tex] = tempTex;
	++tex;

	//display.LoadTex(L"win.png",0,0,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(0,0,0),&textures[tex].texInfo,0,&textures[tex].objTex);
	tempTex = *resMan.getTexture(L"win.png");
	textures[tex] = tempTex;
	++tex;

	//world Model base
	display.CreateUncenteredCube(Models[1],1,1,1);
	resMan.addCube(L"FloorBase",1,1,1,false);
	//create enemy model
	display.CreateUVCube(Models[2],2,2,1);
	resMan.addCube(L"EnemyMod",2,2,1,true);
	//floor mat
	materials[1].Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	materials[1].Diffuse = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);		// Diffuse color reflected
	materials[1].Emissive = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);		// Emissive color reflected
	materials[1].Specular = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);		// Specular
	materials[1].Power = 0.0f;										// Specular highlight intensity
	//wall mat
	materials[2].Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	materials[2].Diffuse = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);		// Diffuse color reflected
	materials[2].Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);		// Emissive color reflected
	materials[2].Specular = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);		// Specular
	materials[2].Power = 0.0f;										// Specular highlight intensity
	//enemy mat
	materials[3].Ambient = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);		// Ambient color reflected
	materials[3].Diffuse = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);		// Diffuse color reflected
	materials[3].Emissive = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// Emissive color reflected
	materials[3].Specular = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);		// Specular
	materials[3].Power = 0.0f;										// Specular highlight intensity
	//test set texture for world
	Models[1].objTex = textures[0].objTex;
	
	
	
	//TODO: update all init loading

	//end art load
	sneak.init(*resMan.getModel(L"FloorBase"),&materials[1],&materials[2],resMan.getTexture(L"playtex.bmp")->objTex,resMan.getTexture(L"enemy.png")->objTex,*resMan.getModel(L"EnemyMod"),&materials[3]);
	sneak.setPlayPos(curPlay,0,0);
	menuSys.reset();
	//set sprite tex
	curSpri.tex = resMan.getTexture(L"playtex.bmp")->objTex;
	curSpri.texinfo = resMan.getTexture(L"playtex.bmp")->texInfo;
	menuSys.setMouseSprite(curSpri);

	talks.init(&resMan);

	Menu tempmenu;
	tempmenu.battleReset();
	tempmenu.setMouseSprite(curSpri);
	batMan.Init(textures,tex);

	//load music
	soundSys.loadStream("MGSMain.mp3",0);
	soundSys.loadStream("MGSSneak.mp3",1);
	soundSys.loadStream("battle.mp3",2);
	//load sounds
	soundSys.load("MGSAleartSound.wav",0);
	//start menu music
	soundSys.PlayStream(0,musicMute);
}

//soundSys.load("FileName",&sound); to load a sound
//soundSys.loadStream("FileName",&sound); to load a sound to steam
//soundSys.Play(sound); to play a sound
//soundSys.PlayStream(sound,bMuted); to play or mute stream

void PokeGear::update()
{
	Pos temp;
	int numobjs = 0,numSprits = 0,numText = 0;
	int tempInt;
	input.Update(keyboard,mouse);
	renderInfo tempRend;
	switch(curState)
	{
	case MainMenu:
		menuSys.GetRender(Sprites[numSprits],numSprits,Text,numText);
		tempRend.tex = resMan.getTexture(L"Pokegearsolid.png")->objTex;
		D3DXMatrixIdentity(&tempRend.matrix);
		D3DXMatrixScaling(&tempRend.matrix,1.3f,1.3f,1.3f);
		Sprites[numSprits] = tempRend;
		++numSprits;
		if((mouse.rgbButtons[0]&0x80)||(keyboard[DIK_RETURN]&0x80))
		{
			if(menuSys.getPushed(tempInt,menuPushed))
			{
				switch(tempInt)
				{
				case 0:
					curState = story;
					soundSys.PlayStream(0,true);
					soundSys.PlayStream(1,musicMute);
					break;
				case 2:
					curState = options;
					menuSys.OptionsReset();
					break;
				case 3:
					curState = credits;
					menuSys.CreditsReset();
					break;
				case 4:
					PostQuitMessage(0);
					break;
				}
			}
		}
		menuSys.Update(keyboard,mouse,menuPushed);
		break;
	case options:
		menuSys.GetRender(Sprites[numSprits],numSprits,Text,numText);
		if((mouse.rgbButtons[0]&0x80)||(keyboard[DIK_RETURN]&0x80))
		{
			if(menuSys.getPushed(tempInt,menuPushed))
			{
				switch(tempInt)
				{
				case 4:
					curState = MainMenu;
					menuSys.reset();
					break;
				}
			}
		}
		menuSys.Update(keyboard,mouse,menuPushed);
		break;
	case credits:
		menuSys.GetRender(Sprites[numSprits],numSprits,Text,numText);
		if((mouse.rgbButtons[0]&0x80)||(keyboard[DIK_RETURN]&0x80))
		{
			if(menuSys.getPushed(tempInt,menuPushed))
			{
				switch(tempInt)
				{
				case 4:
					curState = MainMenu;
					menuSys.reset();
					break;
				}
			}
		}
		menuSys.Update(keyboard,mouse,menuPushed);
		break;
	case stealth:
		//update and get render for map and ents
		tempInt = sneak.Update(keyboard,bCanInput,mouse,curPlay,&soundSys);
		sneak.getRend(D3Objs,numobjs,Sprites,numSprits,Text,numText);
		switch(tempInt)
		{
		case 0:
			temp = curPlay.getRen();
			//move cam
			camera.cam_pos.x = temp.X;
			camera.cam_pos.y = temp.Y;
			camera.cam_look_pos.x = temp.X;
			camera.cam_look_pos.y = temp.Y;
			//add player to draw list
			D3DXMatrixTranslation(&resMan.getModel(L"PlayerModel")->matrix,temp.X,temp.Y,temp.Z);
			D3Objs[numobjs] = *resMan.getModel(L"PlayerModel");
			D3DXMatrixTranslation(&resMan.getModel(L"PlayerModel")->matrix,temp.X,temp.Y,temp.Z);
			++numobjs;
			break;
		case 1:
			curState = battle;
			soundSys.PlayStream(1,true);
			soundSys.PlayStream(2,musicMute);
			break;
		case 2:
			newscene = true;
			curState = story;
			break;
		case 3:
			curState = victory;
			menuSys.setQuitMenu();
			break;
		}
		//end stealth
		break;
	case story:
		talks.update(keyboard,bCanInput2,newscene);
		talks.getRend(Sprites,numSprits,Text,numText);
		if(talks.getname() == "endscene")
		{
			curState = stealth;
		}
		break;
	case battle:
		batMan.Update(keyboard,mouse,Sprites,numSprits,Text,numText, menuPushed,curState,soundSys,menuSys);
		break;
	case GameOver:
		menuSys.GetRender(Sprites[numSprits],numSprits,Text,numText);
		tempRend.tex = textures[14].objTex;
		D3DXMatrixIdentity(&tempRend.matrix);
		D3DXMatrixScaling(&tempRend.matrix,0.6f,0.6f,0.6f);
		Sprites[numSprits] = tempRend;
		++numSprits;
		if((mouse.rgbButtons[0]&0x80)||(keyboard[DIK_RETURN]&0x80))
		{
			if(menuSys.getPushed(tempInt,menuPushed))
			{
				switch(tempInt)
				{
				case 0:
					PostQuitMessage(0);
					break;
				}
			}
		}
		menuSys.Update(keyboard,mouse,menuPushed);
		break;
	case victory:
		menuSys.GetRender(Sprites[numSprits],numSprits,Text,numText);
		tempRend.tex = textures[15].objTex;
		D3DXMatrixIdentity(&tempRend.matrix);
		Sprites[numSprits] = tempRend;
		++numSprits;
		if((mouse.rgbButtons[0]&0x80)||(keyboard[DIK_RETURN]&0x80))
		{
			if(menuSys.getPushed(tempInt,menuPushed))
			{
				switch(tempInt)
				{
				case 0:
					PostQuitMessage(0);
					break;
				}
			}
		}
		menuSys.Update(keyboard,mouse,menuPushed);
		break;
		break;
	}
	display.Render(camera,D3Objs,numobjs,Sprites,numSprits,Text,numText);
	soundSys.update();
}

void PokeGear::shutdown()
{
	resMan.clear();
	//TODO: move resource clean up to resMan
	for(int i = 0;i<maxModels;++i)
	{
		if(Models[i].obj != 0)
		{
			Models[i].objDec->Release();
			Models[i].objDec = 0;
			Models[i].objInd->Release();
			Models[i].objInd = 0;
			Models[i].obj->Release();
			Models[i].obj = 0;
		}
	}
	/*
	for(int i = 0;i<maxtexture;++i)
	{
		if(textures[i].objTex!=0)
		{
			textures[i].objTex->Release();
			textures[i].objTex = 0;
		}
	}
	*/
	sneak.shutdown();
	input.ShutDown();
	display.Shutdown();
}

PokeGear::~PokeGear()
{
	shutdown();
}