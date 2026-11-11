#pragma once
#include <SDL3/SDL.h>

class Tile
{
public:

	bool Walkable;
	SDL_Texture* Texture;
	SDL_FRect Rect;
	Tile* North;
	Tile* East;
	Tile* South;
	Tile* West;

	void SetNeighbour();
	void Configure(SDL_Color& _colour, float _x, float _y, float _size, SDL_Texture* _texture[]);
	bool CompareColours(SDL_Color& _col1, SDL_Color& _col2);


};