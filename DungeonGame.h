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

const static char* RoomFiles[]{ "Data/Rooms/Room01.bmp", "Data/Rooms/Room02.bmp", "Data/Rooms/Room03.bmp", "Data/Rooms/Room04.bmp", "Data/Rooms/Room05.bmp" };
const static std::string TileTexturePaths[]{ "Sprites/Tile_Grey_base.bmp", "Sprites/Tile_carpet_base.bmp" };
const int TileTextureAmount = sizeof(TileTexturePaths) / sizeof(TileTexturePaths[0]);

const static int RoomSize = 10;

const static int NumRoomsX = 10;
const static int NumRoomsy = 10;

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
	SDL_Texture* TileTextures[TileTextureAmount];
	
	Tile Tiles[RoomSize][RoomSize];
};

