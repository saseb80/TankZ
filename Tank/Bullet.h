#pragma once
#include "GameObject.h"
#include<list>
class Bullet : public GameObject
{
public:
	void Init(Platform *platform) override;
	void Draw() override;
	Bullet(float x, float y, float a, float r, float v);
	~Bullet();
	bool Collision();
	void Update() override;
	
private:
	float angle;
	Image *image;
	Platform *platform;
	float velocity;
	
};

