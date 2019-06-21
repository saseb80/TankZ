#include "Bullet.h"
#include "Collision.h"
#include<ctime>

Bullet::Bullet(float x,float y,float a,float r,float v)
{
	positionX = x;
	positionY = y;
	angle = a;
	radius = r;
	velocity = v;
}

Bullet::~Bullet()
{	
		delete image;	
}

void Bullet::Init(Platform *platform)
{
	image = new Image();
	image->LoadImage("../Assets/Images/Bullet.png");
	this->platform = platform;
}

void Bullet::Draw()
{
	platform->RenderImage(image, positionX, positionY, angle);
}

void Bullet::Update()
{
	positionX += (float)cos((angle * M_PI) / 180) * 9;
	positionY += (float)sin((angle * M_PI) / 180) * 9;
}
