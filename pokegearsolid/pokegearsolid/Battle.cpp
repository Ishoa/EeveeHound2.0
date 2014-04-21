// Battle system by josh

#pragma once
#include "Battle.h"


Battle::Battle() {
	curtextincrement = 0;
}


Battle::~Battle() {

}


Battle::Battle(Menu a_battlemenu, int a_numsprites, renderInfo* a_sprites) {
	setBattleMenu(a_battlemenu);
	for(int i = 0; i < a_numsprites; ++i) {
		sprites[i] = a_sprites[i];
	}

}


void Battle::Init(ResourceManager* resMan) {
	srand(time(NULL));
	renderInfo tempCur;
	tempCur.tex = resMan->getTexture(L"playtex.bmp")->objTex;
	tempCur.texinfo = resMan->getTexture(L"playtex.bmp")->texInfo;
	
	D3DXMATRIX matrixlovetwo;
	D3DXMATRIX matrixlovetwo2;
	D3DXMATRIX matrixlovetwo3;
	D3DXMatrixIdentity(&matrixlovetwo);
	D3DXMatrixIdentity(&matrixlovetwo2);
	D3DXMatrixIdentity(&matrixlovetwo3);

	tempCur.matrix = matrixlovetwo;
	battlemenu.setMouseSprite(tempCur);
	curnumsprites = 0;
	for(int i = 3; i < 9; ++i) {
		D3DXMatrixIdentity(&matrixlovetwo);
		D3DXMatrixIdentity(&matrixlovetwo2);
		D3DXMatrixIdentity(&matrixlovetwo3);
		if(i == 3) {
			D3DXMatrixTranslation(&matrixlovetwo,0,0,0);
			D3DXMatrixScaling(&matrixlovetwo2,3.3f,3.3f,3.3f);
		}
		else if (i == 4) {
			D3DXMatrixTranslation(&matrixlovetwo,75,300,0);
			D3DXMatrixScaling(&matrixlovetwo2,2.0f,2.0f,2.0f);
		}
		else {
			D3DXMatrixTranslation(&matrixlovetwo,475,50,0);
			D3DXMatrixScaling(&matrixlovetwo2,2.0f,2.0f,2.0f);
		}
		
		D3DXMatrixMultiply(&matrixlovetwo3, &matrixlovetwo2, &matrixlovetwo);
		
		
		sprites[i-3].matrix = matrixlovetwo3;

		++curnumsprites;
	}
	//get background
	sprites[0].tex = resMan->getTexture(L"battlebackground.png")->objTex;
	sprites[0].texinfo = resMan->getTexture(L"battlebackground.png")->texInfo;
	//get battlepicachu
	sprites[1].tex = resMan->getTexture(L"battlepikachu.png")->objTex;
	sprites[1].texinfo = resMan->getTexture(L"battlepikachu.png")->texInfo;
	//get battle ratata
	sprites[2].tex = resMan->getTexture(L"battlerattata.png")->objTex;
	sprites[2].texinfo = resMan->getTexture(L"battlerattata.png")->texInfo;
	//get battle zubat
	sprites[3].tex = resMan->getTexture(L"battlezubat.png")->objTex;
	sprites[3].texinfo = resMan->getTexture(L"battlezubat.png")->texInfo;
	//get battle koffing
	sprites[4].tex = resMan->getTexture(L"battlekoffing.png")->objTex;
	sprites[4].texinfo = resMan->getTexture(L"battlekoffing.png")->texInfo;
	//get battle ekans
	sprites[5].tex = resMan->getTexture(L"battleekans.png")->objTex;
	sprites[5].texinfo = resMan->getTexture(L"battleekans.png")->texInfo;
}


//LPCWSTR terribleJankyIntToLPCWSTR(int a);


void Battle::battleStart(Pokemon a_pikachu, Pokemon a_enemy) {
	
}


void Battle::menuReset(Pokemon a_pikachu, Pokemon a_enemy) {
	battlemenu.battleReset();
	//wchar_t tempwchar_t[256];
	D3DXCOLOR tempcolor = D3DXCOLOR(0.0f,0.0f,0.0f,1.0f);
	curtextincrement = 0;
	swprintf_s(charactertempthingy[curtextincrement], a_pikachu.getName());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement];// Pikachu's name
	battletext[curtextincrement].rec.top = 450;
	battletext[curtextincrement].rec.bottom = 525;
	battletext[curtextincrement].rec.left = 600;
	battletext[curtextincrement].rec.right = 800;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"hp:");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // hp's hp:
	battletext[curtextincrement].rec.top = 525;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 490;
	battletext[curtextincrement].rec.right = 720;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getCurHP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // Pikachu's curhp
	battletext[curtextincrement].rec.top = 525;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 555;
	battletext[curtextincrement].rec.right = 750;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"/");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // hp's slash
	battletext[curtextincrement].rec.top = 525;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 610;
	battletext[curtextincrement].rec.right = 780;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMaxHP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikach's max hp
	battletext[curtextincrement].rec.top = 525;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 660;
	battletext[curtextincrement].rec.right = 800;
	++curtextincrement;
	//  enemy start
	swprintf_s(charactertempthingy[curtextincrement], a_enemy.getName());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement];// Enemy's name
	battletext[curtextincrement].rec.top = 75;
	battletext[curtextincrement].rec.bottom = 0;
	battletext[curtextincrement].rec.left = 0;
	battletext[curtextincrement].rec.right = 200;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"hp:");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // hp's hp:
	battletext[curtextincrement].rec.top = 150;
	battletext[curtextincrement].rec.bottom = 75;
	battletext[curtextincrement].rec.left = 0;
	battletext[curtextincrement].rec.right = 100;
	battletext[curtextincrement].textColor = tempcolor;	
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_enemy.getCurHP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // enemy's curhp
	battletext[curtextincrement].rec.top = 150;
	battletext[curtextincrement].rec.bottom = 75;
	battletext[curtextincrement].rec.left = 10;
	battletext[curtextincrement].rec.right = 160;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"/");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // hp's slash
	battletext[curtextincrement].rec.top = 150;
	battletext[curtextincrement].rec.bottom = 75;
	battletext[curtextincrement].rec.left = 10;
	battletext[curtextincrement].rec.right = 210;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_enemy.getMaxHP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // enemy's max hp
	battletext[curtextincrement].rec.top = 150;
	battletext[curtextincrement].rec.bottom = 75;
	battletext[curtextincrement].rec.left = 60;
	battletext[curtextincrement].rec.right = 210;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
}


void Battle::menuResetWithMoves(Pokemon a_pikachu, Pokemon a_enemy) {
	battlemenu.battleResetWithMoves(a_pikachu);
	D3DXCOLOR tempcolor = D3DXCOLOR(0.0f,0.0f,0.0f,1.0f);
	curtextincrement = 0;
	swprintf_s(charactertempthingy[curtextincrement], a_pikachu.getName());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement];// Pikachu's name
	battletext[curtextincrement].rec.top = 450;
	battletext[curtextincrement].rec.bottom = 525;
	battletext[curtextincrement].rec.left = 600;
	battletext[curtextincrement].rec.right = 800;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"hp:");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // hp's hp:
	battletext[curtextincrement].rec.top = 525;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 490;
	battletext[curtextincrement].rec.right = 720;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getCurHP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // Pikachu's curhp
	battletext[curtextincrement].rec.top = 525;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 555;
	battletext[curtextincrement].rec.right = 750;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"/");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // hp's slash
	battletext[curtextincrement].rec.top = 525;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 610;
	battletext[curtextincrement].rec.right = 780;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMaxHP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikach's max hp
	battletext[curtextincrement].rec.top = 525;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 660;
	battletext[curtextincrement].rec.right = 800;
	++curtextincrement;
	//  enemy start
	swprintf_s(charactertempthingy[curtextincrement], a_enemy.getName());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement];// Enemy's name
	battletext[curtextincrement].rec.top = 75;
	battletext[curtextincrement].rec.bottom = 0;
	battletext[curtextincrement].rec.left = 0;
	battletext[curtextincrement].rec.right = 200;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"hp:");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // hp's hp:
	battletext[curtextincrement].rec.top = 150;
	battletext[curtextincrement].rec.bottom = 75;
	battletext[curtextincrement].rec.left = 0;
	battletext[curtextincrement].rec.right = 100;
	battletext[curtextincrement].textColor = tempcolor;	
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_enemy.getCurHP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // enemy's curhp
	battletext[curtextincrement].rec.top = 150;
	battletext[curtextincrement].rec.bottom = 75;
	battletext[curtextincrement].rec.left = 10;
	battletext[curtextincrement].rec.right = 160;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"/");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // hp's slash
	battletext[curtextincrement].rec.top = 150;
	battletext[curtextincrement].rec.bottom = 75;
	battletext[curtextincrement].rec.left = 10;
	battletext[curtextincrement].rec.right = 210;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_enemy.getMaxHP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // enemy's max hp
	battletext[curtextincrement].rec.top = 150;
	battletext[curtextincrement].rec.bottom = 75;
	battletext[curtextincrement].rec.left = 60;
	battletext[curtextincrement].rec.right = 210;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	// Start move pp's
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMove(0).getCurPP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 1st move's curpp
	battletext[curtextincrement].rec.top = 480;
	battletext[curtextincrement].rec.bottom = 525;
	battletext[curtextincrement].rec.left = 10;
	battletext[curtextincrement].rec.right = 160;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"/");
	battletext[curtextincrement].text = L"/"; // pikachu's 1st move's slash
	battletext[curtextincrement].rec.top = 480;
	battletext[curtextincrement].rec.bottom = 525;
	battletext[curtextincrement].rec.left = 10;
	battletext[curtextincrement].rec.right = 210;
	++curtextincrement;
	
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMove(0).getMaxPP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 1st move's maxpp
	battletext[curtextincrement].rec.top = 480;
	battletext[curtextincrement].rec.bottom = 525;
	battletext[curtextincrement].rec.left = 60;
	battletext[curtextincrement].rec.right = 210;
	++curtextincrement;
	// second move
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMove(1).getCurPP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 2nd move's curpp
	battletext[curtextincrement].rec.top = 480;
	battletext[curtextincrement].rec.bottom = 525;
	battletext[curtextincrement].rec.left = 210;
	battletext[curtextincrement].rec.right = 360;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"/");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 2nd move's slash
	battletext[curtextincrement].rec.top = 480;
	battletext[curtextincrement].rec.bottom = 525;
	battletext[curtextincrement].rec.left = 210;
	battletext[curtextincrement].rec.right = 410;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMove(1).getMaxPP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 2nd move's maxpp
	battletext[curtextincrement].rec.top = 480;
	battletext[curtextincrement].rec.bottom = 525;
	battletext[curtextincrement].rec.left = 260;
	battletext[curtextincrement].rec.right = 410;
	++curtextincrement;
	// third move pp
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMove(2).getCurPP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 3rd move's curpp
	battletext[curtextincrement].rec.top = 565;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 10;
	battletext[curtextincrement].rec.right = 160;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"/");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 3rd move's slash
	battletext[curtextincrement].rec.top = 565;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 10;
	battletext[curtextincrement].rec.right = 210;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMove(2).getMaxPP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 3rd move's maxpp
	battletext[curtextincrement].rec.top = 565;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 60;
	battletext[curtextincrement].rec.right = 210;
	++curtextincrement;
	// fourth move
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMove(3).getCurPP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 4th move's curpp
	battletext[curtextincrement].rec.top = 565;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 210;
	battletext[curtextincrement].rec.right = 360;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"/");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's fortuh move's slash
	battletext[curtextincrement].rec.top = 565;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 210;
	battletext[curtextincrement].rec.right = 410;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"%d", a_pikachu.getMove(3).getMaxPP());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement]; // pikachu's 4th move's maxpp
	battletext[curtextincrement].rec.top = 565;
	battletext[curtextincrement].rec.bottom = 600;
	battletext[curtextincrement].rec.left = 260;
	battletext[curtextincrement].rec.right = 410;
	++curtextincrement;

}


void Battle::addText(Pokemon a_user, Move a_move) {
	D3DXCOLOR tempcolor = D3DXCOLOR(0.0f,0.0f,0.0f,1.0f);
	swprintf_s(charactertempthingy[curtextincrement], a_user.getName());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement];// User's name
	battletext[curtextincrement].rec.top = 375;
	battletext[curtextincrement].rec.bottom = 450;
	battletext[curtextincrement].rec.left = 300;
	battletext[curtextincrement].rec.right = 500;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], L"used");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement];// Used
	battletext[curtextincrement].rec.top = 375;
	battletext[curtextincrement].rec.bottom = 450;
	battletext[curtextincrement].rec.left = 425;
	battletext[curtextincrement].rec.right = 625;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
	swprintf_s(charactertempthingy[curtextincrement], a_move.getName());
	battletext[curtextincrement].text = charactertempthingy[curtextincrement];// User's move's name
	battletext[curtextincrement].rec.top = 375;
	battletext[curtextincrement].rec.bottom = 450;
	battletext[curtextincrement].rec.left = 575;
	battletext[curtextincrement].rec.right = 775;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
}


void Battle::addYouWin() {
	D3DXCOLOR tempcolor = D3DXCOLOR(0.0f,0.0f,0.0f,1.0f);
	swprintf_s(charactertempthingy[curtextincrement], L"You win!");
	battletext[curtextincrement].text = charactertempthingy[curtextincrement];// User's name
	battletext[curtextincrement].rec.top = 300;
	battletext[curtextincrement].rec.bottom = 375;
	battletext[curtextincrement].rec.left = 300;
	battletext[curtextincrement].rec.right = 500;
	battletext[curtextincrement].textColor = tempcolor;
	++curtextincrement;
}


void Battle::GetBattleRender(renderInfo a_sprites[],int& a_numsprites,TextStruct tex[],int& text, Species a_enemy) {
	
	for(int i = 0;i<curtextincrement;++i) {
		tex[text] = battletext[i];
		++text;
	}
	for(int i = 0; i < 2; ++i) {
		a_sprites[a_numsprites] = sprites[i];
		++a_numsprites;
	}

	if(a_enemy == RATATA) {
		a_sprites[a_numsprites] = sprites[2];
		++a_numsprites;
	}
	else if(a_enemy == ZUBAT) {
		a_sprites[a_numsprites] = sprites[3];
		++a_numsprites;
	}
	else if(a_enemy == KOFFING) {
		a_sprites[a_numsprites] = sprites[4];
		++a_numsprites;
	}
	else if(a_enemy == EKANS) {
		a_sprites[a_numsprites] = sprites[5];
		++a_numsprites;
	}
	battlemenu.GetRender(a_sprites[a_numsprites], a_numsprites, tex, text);

}


void Battle::setBattleMenu(Menu a_battlemenu) {
	battlemenu = a_battlemenu;
}


Menu Battle::getBattleMenu() {
	return battlemenu;
}


void Battle::addSprite(renderInfo a_newsprite) {
	if(curnumsprites < 20) {
		sprites[curnumsprites] = a_newsprite;
		incrementCurNumSprites();
	}
}


renderInfo Battle::getSprite(int a_index) {
	return sprites[a_index];
}


int Battle::getCurNumSprites() {
	return curnumsprites;
}


void Battle::incrementCurNumSprites() {
	++curnumsprites;
}


void Battle::Update(char keyboard[],DIMOUSESTATE2& mouse,bool &pushed) {
	battlemenu.Update(keyboard,mouse,pushed);

}

