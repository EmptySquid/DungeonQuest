#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Player.h"
#include "GameCharacter.h"

//Texture Paths (Temp)
const static std::string Path_Hero = "Sprites/Hero_sword.png";

class DungeonGame
{
public:
	DungeonGame();  //Constructor
	~DungeonGame(); //Destructor
	void Awake(SDL_Renderer*);
	void Update(SDL_Renderer*);
	void LoadTextures(SDL_Renderer*);

	//Variables
	float tileSize = 100;
	Player* Hero;
};

