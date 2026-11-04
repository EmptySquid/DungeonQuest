#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "Player.h"
#include "GameCharacter.h"
#include "Enemy.h"
#include "Tile.h"

//Texture Paths (Temp)
const static std::string Path_Hero = "Sprites/Hero_sword.png";

const static int RoomSize = 10;

class DungeonGame
{
public:
	DungeonGame();  //Constructor
	~DungeonGame(); //Destructor
	void Awake(SDL_Renderer*);
	void Update(SDL_Renderer*);
	void LoadTextures(SDL_Renderer*);
	void Input(std::string);
	void LoadRoom(const char* filename);

	//Variables
	float TileSize = 100;
	Player* Hero;
	Enemy* Goblin;

	Tile Tiles[RoomSize][RoomSize];
};

