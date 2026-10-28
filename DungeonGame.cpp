#include "DungeonGame.h"

DungeonGame::DungeonGame()
{
}

DungeonGame::~DungeonGame()
{
}

void DungeonGame::Awake(SDL_Renderer* _renderer)
{
	std::cout << "You have entered the dungeon. ";
	this->Hero = new Player;
	this->Hero->Initialize(_renderer, tileSize, "Sprites/Hero_sword.png");
}

void DungeonGame::Update(SDL_Renderer* _renderer)
{
	SDL_RenderTexture(_renderer, this->Hero->Texture, NULL, &Hero->Rect);
}

void DungeonGame::LoadTextures(SDL_Renderer* _renderer)
{
}
