#pragma once
#include "GameObject.h"
#include "Image.h"
#include <list>

class Background : public GameObject
{
public:
	Background();
	void Init(Platform *platform) override;
	void Update() override;
	void Draw() override;
	~Background();
private:	
	Image *image;
	Platform *platform;
};

	


