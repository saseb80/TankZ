#include "Menu.h"
#include "Game.h"
#include<iostream>

Menu::Menu()
{
	
}

Menu::~Menu()
{
}

void Menu::Init(Platform * platform, GameStateManager *manager)
{
	std::cout << " Menu Init" << std::endl;
	this->platform = platform;
	this->manager = manager;
	background = new Image();
	powSDL2 = new Image();
	powSDL2->LoadImage("../Assets/Images/powered.png");
	//background->LoadImage("../Assets/Images/background.png");
	background->LoadImage("../Assets/Images/portada.png");
	
}

void Menu::Draw()
{
	contador += 1;
	platform->RenderClear();
	std::cout << " Menu Draw" << std::endl;
	
	
	if (contador <= 220)
	{
		platform->RenderImage(powSDL2, 0, 0, 0);
	}

	if (contador >= 220)
	{			
		platform->RenderImage(background, 0, 0, 0);
	}

	platform->RenderPresent();
	

	
	
}

bool Menu::Input(int keyInput)
{
	std::cout << " Menu Input" << std::endl;
	if (keyInput == 27)
	{
		exit(1);
	}
	if (keyInput == 13)
	{ 
		manager->SetState(new Game());
	}
	//if (keyInput == 46)
	//{
		//cambioImagen = true;
	//}
	return false;
}

void Menu::Update()
{
	std::cout << " Menu Update" << std::endl;
}

void Menu::Close()
{
	std::cout << " Close Init" << std::endl;
}