#pragma once
#include"Tile.h"
#include"Platform.h"
#include<vector>
#include<list>
#include"GameObject.h"

class Map : GameObject
{
private:
	std::vector<Tile*> tiles;
	Platform *platform;
	std::list<GameObject *> *bulletPool;

	std::vector<Tile*> tiles2;

	float positionX, positionY;
	Image *background;
	
	float radius;
	int energy;

public:
	Map();
	~Map();
	void Init(Platform *platform) override;
	void Draw() override;
	void Update() override;
	void SetPool(std::list<GameObject *> *bulletPool);
};

