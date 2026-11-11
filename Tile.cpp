#include "Tile.h"
#include <iostream>

void Tile::SetNeighbour()
{

}

void Tile::Configure(SDL_Color& _colour, float _x, float _y, float _size, SDL_Texture* _tileTextures[])
{
	SDL_Color black = { 0, 0, 0, 255 };

	Walkable = CompareColours(_colour, black);
	if (Walkable)
	{
		this->Texture = _tileTextures[0];
	}
	else
	{
		this->Texture = _tileTextures[1];
	}

	Rect.x = _x;
	Rect.y = _y;
	Rect.w = _size;
	Rect.h = _size;
}

bool Tile::CompareColours(SDL_Color& _col1, SDL_Color& _col2)
{
	return _col1.r == _col2.r && _col1.g == _col2.g && _col1.b == _col2.b;
}