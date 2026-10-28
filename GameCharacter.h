#pragma once
#include <SDL3_image/SDL_image.h>
#include <iostream>

class GameCharacter
{
public:
	GameCharacter();  //Constructor
	~GameCharacter(); //Destructor
	void SetPosition(float, float );
	void SetSize(float, float);
	void Initialize(SDL_Renderer*, float, std::string);

	//Variables
	std::string ImagePath;
	SDL_Texture* Texture;
	SDL_FRect Rect;
	int PosX;
	int PosY;
};

