#pragma once
#include <SDL3/SDL.h>

class Tile
{
public:
	
	bool Walkable;
	SDL_Texture* Texture;
	SDL_FRect Rect;

	void Configure(SDL_Color& _colour);
	bool CompareColours(SDL_Color& _col1, SDL_Color& _col2)


};

