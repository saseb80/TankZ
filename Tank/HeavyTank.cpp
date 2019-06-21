#include "HeavyTank.h"
#include "Collision.h"
#include <list>
#include<cstdlib>
#include<ctime>

HeavyTank::HeavyTank()
{
}

void HeavyTank::Init(Platform *platform)
{
	if (energy == true) {

	
	image = new Image();
	image2 = new Image();
	image->LoadImage("../Assets/Images/HeavyTank2.png");
	image->LoadImage("../Assets/Images/HeavyTank.png");
	positionX = 700;
	positionY = 900;
	angle = 90;
	this->platform = platform;
	radius = 40;
	energyY = 300;
	}
}

void HeavyTank::Update()
{
	

	
	positionX += (float)cos((angle * M_PI) / 180) * 2.0;
	positionY += (float)sin((angle * M_PI) / 180) * 2.0;
	
	if (Collision())
	{
		positionY -= (float)sin((angle * M_PI) / 180) * 20;
		positionX -= (float)cos((angle * M_PI) / 180) * 20;
		srand(time(0));		
		angle += rand()%360;
		if (angle < 20)
			angle += 10;
		energy == false;
		energyY -= 3;
	}

	if (energyY <= 0) {
		positionY = 700;
		positionX = 900;
		energyY = 300;
	}
	
	angle = (int)angle % 360;
}

void HeavyTank:: Draw()
{
	if (energy >0)
	{
		platform->RenderImage(image, positionX, positionY, angle);
	}
	
}

void HeavyTank::SetPool(std::list<GameObject *> *bulletPool)
{
	this->bulletPool = bulletPool;
}

bool HeavyTank::Collision()
{
	for (auto object : *bulletPool)
	{
		if (Collision::BoxCollision(positionX, positionY, image->GetWidth(), image->GetHeight(),
			object->GetPositionX(), object->GetPositionY(), 32, 32))
		{
			return true;			
		}
	}
	return false;
}

HeavyTank::~HeavyTank()
{
	if (energyY <= 0) {
		delete image;
	}

}