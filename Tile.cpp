#include "Tile.h"
#include <iostream>

void Tile::Configure(SDL_Color& _colour)
{
	SDL_Color black = { 0, 0, 0, 255 };

	Walkable = CompareColours(_colour, black);
	std::cout << Walkable;
	if (CompareColours(_colour, black))
	{
		Walkable = false;
		return;
	}
	else {
		Walkable = true;
	}
}

bool Tile::CompareColours(SDL_Color& _col1, SDL_Color& _col2)
{
	return _col1.r == _col2.r;
}