#include "Map.h"

Map::Map()
{
	float r = 2;
	for (int xU = 0; xU <= 1920;xU+=32) 
	{
		tiles.push_back(new Tile(xU, 0, r));
	}

	for (int xD = 0; xD <= 1920; xD+=32) 
	{
		tiles.push_back(new Tile(xD, 1048, r));
	}

	for (int yL = 0; yL <= 1080; yL += 32)
	{
		tiles.push_back(new Tile(0, yL, r));
	}

	for (int yR = 0; yR <= 1080; yR += 32) 
	{
		tiles.push_back(new Tile(1948, yR, r));
	}

	/*tiles.push_back(new Tile(64,50, r));
	tiles.push_back(new Tile(96, 50, r));
	tiles.push_back(new Tile(128, 50, r));
	tiles.push_back(new Tile(160, 50, r));
	tiles.push_back(new Tile(192, 50, r));
	tiles.push_back(new Tile(224, 50, r));*/

	for (int i =192; i <= 512; i += 32) 
	{
		tiles.push_back(new Tile(i, 256, r));
	}

	for (int j = 96; j <= 512; j += 32)
	{
		tiles.push_back(new Tile(768, j, r));
	}


	for (int ja = 416; ja <= 832; ja += 32)
	{
		tiles.push_back(new Tile(480, ja, r));
	}

	for (int jd = 1400; jd <= 1920; jd += 32)
	{
		tiles.push_back(new Tile(jd, 480, r));
	}

	for (int jp = 1400; jp <= 1920; jp += 32)
	{
		tiles.push_back(new Tile(jp, 800, r));
	}
	

	
		
}

void Map::SetPool(std::list<GameObject *> *bulletPool)
{
	this->bulletPool = bulletPool;
}

void Map::Init(Platform *platform)
{	
	//Fondo
	background = new Image();
	background->LoadImage("../Assets/Images/Fondito2.png");

	this->platform = platform;
	for (auto tile : tiles)
	{
		tile->Init(platform);
		bulletPool->push_back(tile);
	}

	for (auto tile2 : tiles2) 
	{
		tile2->Init(platform);
	}

	
	
}
void Map::Update()
{

}

void Map::Draw()
{
	for (auto tile : tiles)
	{
		tile->Draw();
	}

	for (auto tile2 : tiles2)
	{
		tile2->Draw();
	}

	platform->RenderImage(background, 0, 0,0);
}

Map::~Map()
{
}
