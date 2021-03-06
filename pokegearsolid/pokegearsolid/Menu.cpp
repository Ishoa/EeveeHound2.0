//menu thing
//by Tyler van Gastel

#include "Menu.h"

Menu::Menu()
{
	lastBut = 0;
	for(int i = 0;i<numBut;i++)
	{
		buttons[i].setActive(true);
		buttons[i].setLoc(100+60*i,150+60*i,300,500);
	}
	buttons[0].setlable(L"Play");
	buttons[1].setlable(L"Help");
	buttons[2].setlable(L"Options");
	buttons[3].setlable(L"Credits");
	buttons[4].setlable(L"Quit");
	for(int i = 5;i<numBut;++i)
	{
		buttons[i].setlable(L"Blank");
		buttons[i].setVisAct(false);
	}
	width = 800;
	height = 600;
}

void Menu::reset()
{
	int w,h;
	//store curent res
	h = height;
	w = width;
	//change res for ez placment
	height = 600;
	width = 800;
	setRes(width,height);
	for(int i = 0;i<numBut;i++)
	{
		buttons[i].setActive(true);
		buttons[i].setLoc(250+60*i,325+60*i,500,700);
	}
	buttons[0].setlable(L"Play");
	buttons[0].setVisAct(true);
	buttons[1].setlable(L"Intro");
	buttons[1].setVisAct(false);
	buttons[2].setlable(L"Controls");
	buttons[2].setVisAct(true);
	buttons[3].setlable(L"Credits");
	buttons[3].setVisAct(true);
	buttons[4].setlable(L"Quit");
	buttons[4].setVisAct(true);
	for(int i = 5;i<numBut;++i)
	{
		buttons[i].setlable(L"Blank");
		buttons[i].setVisAct(false);
	}
	//reset res
	setRes(800,600);
}


void Menu::OptionsReset() {
	int w,h;
	//store curent res
	h = height;
	w = width;
	//change res for ez placment
	height = 600;
	width = 800;
	setRes(width,height);
	for(int i = 0;i<numBut;i++)
	{
		buttons[i].setActive(true);
		buttons[i].setLoc(100+60*i,200+60*i,300,500);
	}
	buttons[0].setlable(L"arrow keys for moving");
	buttons[0].setVisAct(true);
	buttons[1].setlable(L"mouse for menus");
	buttons[1].setVisAct(true);
	buttons[2].setlable(L"also arrow keys for menus");
	buttons[2].setVisAct(true);
	buttons[3].setlable(L"Enter or click to select things in menus");
	buttons[3].setVisAct(true);
	buttons[4].setlable(L"Back to Main Menu");
	buttons[4].setVisAct(true);
	for(int i = 5;i<numBut;++i)
	{
		buttons[i].setlable(L"Blank");
		buttons[i].setVisAct(false);
	}
	//reset res
	setRes(800,600);
}


void Menu::CreditsReset() {
	int w,h;
	//store curent res
	h = height;
	w = width;
	//change res for ez placment
	height = 600;
	width = 800;
	setRes(width,height);
	for(int i = 0;i<numBut;i++)
	{
		buttons[i].setLoc(100+60*i,200+60*i,300,500);
	}
	buttons[0].setlable(L"By AJ Rolle, Tyler Van Gastel,\n       and Josh Foley");
	buttons[0].setVisable(true);
	buttons[1].setlable(L"Battle Music from Pokemon");
	buttons[1].setVisAct(false);
	buttons[2].setlable(L"Battle Music from Pokemon");
	buttons[2].setVisable(true);
	buttons[3].setlable(L"Menu music and game music from metal gear");
	buttons[3].setVisable(true);
	buttons[4].setlable(L"Back to main menu");
	buttons[4].setVisAct(true);
	buttons[4].setActive(true);
	for(int i = 5;i<numBut;++i)
	{
		buttons[i].setlable(L"Blank");
		buttons[i].setVisAct(false);
	}
	//reset res
	setRes(800,600);
}




void Menu::battleReset() {
	int w,h;
	//store curent res
	h = height;
	w = width;
	//change res for ez placment
	height = 600;
	width = 800;
	setRes(width,height);
	buttons[0].setActive(true);
	buttons[0].setLoc(450,525,10,210);
	buttons[1].setActive(true);
	buttons[1].setLoc(450,525,210,410);
	buttons[2].setActive(true);
	buttons[2].setLoc(525,600,10,210);
	buttons[3].setActive(true);
	buttons[3].setLoc(525,600,210,410);

	for(int i = 4;i<numBut;++i)
	{
		buttons[i].setActive(false);
		buttons[i].setLoc(100+60*i,150+60*i,300,500);
	}
	buttons[0].setlable(L"Fight");
	buttons[0].setVisAct(true);
	buttons[1].setlable(L"Bag");
	buttons[1].setVisAct(true);
	buttons[2].setlable(L"Pokemon");
	buttons[2].setVisAct(true);
	buttons[3].setlable(L"Run");
	buttons[3].setVisAct(true);
	for(int i = 4;i<numBut;++i)
	{
		buttons[i].setlable(L"Blank");
		buttons[i].setVisAct(false);
	}
	//reset res
	setRes(800,600);
}


void Menu::battleResetWithMoves(Pokemon a_pikachu) {
	int w,h;
	//store curent res
	h = height;
	w = width;
	//change res for ez placment
	height = 600;
	width = 800;
	setRes(width,height);
	buttons[0].setActive(true);
	buttons[0].setLoc(450,525,10,210);
	buttons[1].setActive(true);
	buttons[1].setLoc(450,525,210,410);
	buttons[2].setActive(true);
	buttons[2].setLoc(525,600,10,210);
	buttons[3].setActive(true);
	buttons[3].setLoc(525,600,210,410);

	for(int i = 4;i<numBut;++i)
	{
		buttons[i].setActive(false);
		buttons[i].setLoc(100+60*i,150+60*i,300,500);
	}
	buttons[0].setlable(a_pikachu.getMove(0).getName());
	buttons[0].setVisAct(true);
	buttons[1].setlable(a_pikachu.getMove(1).getName());
	buttons[1].setVisAct(true);
	buttons[2].setlable(a_pikachu.getMove(2).getName());
	buttons[2].setVisAct(true);
	buttons[3].setlable(a_pikachu.getMove(3).getName());
	buttons[3].setVisAct(true);
	for(int i = 4;i<numBut;++i)
	{
		buttons[i].setlable(L"Blank");
		buttons[i].setVisAct(false);
	}
	//reset res
	setRes(800,600);
}


void Menu::setMouseSprite(renderInfo sprite)
{
	cur.setSprite(sprite);
}

int Menu::getState()
{
	return state;
}

void Menu::setState(int in)
{
	state = in;
}

bool Menu::setButton(Button newButton,int index)
{
	if(index>=0&&index<numBut)
	{
		buttons[index] = newButton;
		return true;
	}
	else
	{
		return false;
	}
}

bool Menu::buttonIsPushed(int button)
{
	if(button>=0&&button<numBut)
	{
		return buttons[button].clicked();
	}
	else
	{
		return false;
	}
}

bool Menu::getPushed(int &buttonPushed,bool &pushed)
{
	for(int i = 0;i < numBut;++i)
	{
		if(buttons[i].clicked())
		{
			if(!pushed)
			{
				buttonPushed = i;
				pushed = true;
				return true;
			}
		}
	}
	return false;
}

void Menu::Update(char keyboard[],DIMOUSESTATE2& mouse,bool &pushed)
{
	float x,y;
	cur.move(mouse.lX,mouse.lY);
	cur.getPos(x,y);
	if(x<0)
	{
		x = 0;
	}
	else if(x>width)
	{
		x=width;
	}
	if(y<0)
	{
		y = 0;
	}
	else if(y>height)
	{
		y = height;
	}
	cur.setPos(x,y);
	if((keyboard[DIK_UP]&0x80))
	{
		bool loop = true;
		if(!pushed)
		{
			--lastBut;
			while(loop)
			{
				if(lastBut<0)
				{
					lastBut = numBut-1;
				}
				if(buttons[lastBut].getActive())
				{
					loop = false;
				}
				else
				{
					--lastBut;
				}
			}
			MoveMouseToBut(lastBut);
			pushed = true;
		}
	}
	else if(keyboard[DIK_DOWN]&0x80)
	{
		bool loop = true;
		if(!pushed)
		{
			++lastBut;
			while(loop)
			{
				if(lastBut>=numBut)
				{
					lastBut = 0;
				}
				if(buttons[lastBut].getActive())
				{
					loop = false;
				}
				else
				{
					++lastBut;
				}
			}
			MoveMouseToBut(lastBut);
			pushed = true;
		}
	}
	else if(keyboard[DIK_RETURN]&0x80||mouse.rgbButtons[0]&0x80)
	{
		pushed = true;
	}
	else if(pushed)
	{
		pushed = false;
	}
	for(int i = 0;i<numBut;++i)
	{
		buttons[i].Update(x,y);
	}
}

void Menu::GetRender(renderInfo& mou,int& sprites,TextStruct tex[],int& text)
{
	mou = cur.getRend();
 	++sprites;
	for(int i = 0;i<numBut;++i)
	{
		if(buttons[i].getVisable())
		{
			tex[text] = buttons[i].getTextInf();
			++text;
		}
	}
}

void Menu::getMousePos(int &X,int &Y)
{
	float x,y;
	cur.getPos(x,y);
	X = x;
	Y = y;
}

void Menu::setRes(int w,int h)
{
	width = w;
	height = h;
	//update all the button locations
	for(int i = 0;i<numBut;++i)
	{
		buttons[i].setRes(w,h);
	}
}

void Menu::MoveMouseToBut(int but)
{
	float t,b,l,r;
	if(but<numBut)
	{
		buttons[but].getLoc(t,b,l,r);
		b -= t;
		r -= l;
		b = b/2;
		r = r/2;
		l += r;
		t += b;
		cur.setPos(l,t);
	}
}

Button Menu::getBut(int but)
{
	if(but<numBut&&but>=0)
	{
		return buttons[but];
	}
	else
		return buttons[0];
}

void Menu::setQuitMenu()
{
	for(int i = 0;i<numBut;++i)
	{
		buttons[i].setVisable(false);
	}
	buttons[0].setVisable(true);
	buttons[0].setlable(L"Quit");
	buttons[0].setLoc(100+60*4,150+60*4,300,500);
}