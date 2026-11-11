#include "DungeonGame.h"

DungeonGame::DungeonGame()
{
}

DungeonGame::~DungeonGame()
{
}

void DungeonGame::Awake(SDL_Renderer* _renderer)
{
	//Initialize Player
	std::cout << "You have entered the dungeon. ";
	Hero = new Player;
	Hero->Initialize(_renderer, TileSize, Path_Hero);
	SDL_SetTextureScaleMode(this->Hero->Texture, SDL_SCALEMODE_NEAREST);

	//Initialize Goblin
	Goblin = new Enemy;
	Goblin->Initialize(_renderer, TileSize, "Sprites/Enemy_orc_blue.png");
	Goblin->SetPosition(100, 0);
	SDL_SetTextureScaleMode(this->Goblin->Texture, SDL_SCALEMODE_NEAREST);

	//Loads Tile Textures
	for (int i = 0; i < TileTextureAmount; i++)
	{
		TileTextures[i] = IMG_LoadTexture(_renderer, TileTexturePaths[i].c_str());
		SDL_SetTextureScaleMode(TileTextures[i], SDL_SCALEMODE_NEAREST);
	}

	LoadRoom("Data/Rooms/Room01.bmp");
}

void DungeonGame::Update(SDL_Renderer* _renderer)
{
	for (int x = 0; x < RoomSize; x++)
	{
		for (int y = 0; y < RoomSize; y++)
		{
			SDL_RenderTexture(_renderer, Tiles[x][y].Texture, NULL, &Tiles[x][y].Rect);
		}
	}

	SDL_RenderTexture(_renderer, this->Hero->Texture, NULL, &Hero->Rect);

	SDL_RenderTexture(_renderer, this->Goblin->Texture, NULL, &Goblin->Rect);
}

void DungeonGame::LoadTextures(SDL_Renderer* _renderer)
{
}

void DungeonGame::Input(std::string _dir)
{
	std::cout << _dir;
	if(_dir == "w")
	{
		Hero->SetPosition(Hero->PosX, Hero->PosY - TileSize);
	}

	if (_dir == "s")
	{
		Hero->SetPosition(Hero->PosX, Hero->PosY + TileSize);
	}

	if (_dir == "a")
	{
		Hero->SetPosition(Hero->PosX - TileSize, Hero->PosY );
	}

	if (_dir == "d")
	{
		Hero->SetPosition(Hero->PosX + TileSize, Hero->PosY );
	}
}

void DungeonGame::LoadRoom(const char* filename)
{
	SDL_Surface* surf = SDL_LoadBMP(filename);

	const SDL_PixelFormatDetails* pixelDetails = SDL_GetPixelFormatDetails(surf->format);
	const Uint8 bpp = SDL_BYTESPERPIXEL(surf->format);
	SDL_Color col;

	for (int y = 0; y < surf->h; y++) {
		for (int x = 0; x < surf->w; x++) {
			Uint8* pixel = static_cast<Uint8*>(surf->pixels) + y * surf->pitch + x * bpp;
			SDL_GetRGB(*reinterpret_cast<Uint32*>(pixel), pixelDetails, NULL, &col.r, &col.g,
				&col.b);

			// col now contains pixel colour at position x,y!
			// TODO, configure the tile at x/y with this colour.
			Tiles[x][y].Configure(col, x * TileSize, y * TileSize, TileSize, TileTextures);
		}
	}
}
