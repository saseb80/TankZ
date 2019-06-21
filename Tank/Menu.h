#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Image.h"

class Menu : public GameState
{
private:
	Platform *platform;
	Image *background;
	GameStateManager *manager;
	Image *powSDL2;
	int keyInput;
	int enter;
	bool cambioImagen = false;
	int contador;
public:
	Menu();
	~Menu();
	void Init(Platform * platform, GameStateManager *manager) override;
	void Draw() override;
	bool Input(int keyInput) override;
	void Update() override;
	void Close() override;
};

