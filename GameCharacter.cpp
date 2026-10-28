#include "GameCharacter.h"

GameCharacter::GameCharacter()
{
}

GameCharacter::~GameCharacter()
{
}

void GameCharacter::SetPosition(float _x, float _y)
{
	PosX = Rect.x = _x;
	PosY = Rect.y = _y;
}

void GameCharacter::SetSize(float _w, float _h)
{
	Rect.w = _w;
	Rect.h = _h;
}

void GameCharacter::Initialize(SDL_Renderer* _renderer, float _tileSize, std::string _path)
{
	ImagePath = _path;
	Texture = IMG_LoadTexture(_renderer, ImagePath.c_str());
	SetPosition(0, 0);
	SetSize(_tileSize, _tileSize);
}
