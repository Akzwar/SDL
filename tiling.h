#include "SDL/SDL.h"
#include <string>
class TTile
{
public:
	int x;
	int y;
	int Width;
	int Height;
	int X1(){return x;}
	int X2(){return (x+Width);}
	int Y1(){return y;}
	int Y2(){return (y+Height);}
	SDL_Surface* Texture;
	int ParX;
	int ParY;
	TTile(int x, int y, int Width, int Height)
	{
		this->x=x;
		this->y=y;
		this->Width=Width;
		this->Height=Height;
	}
	~TTile(){SDL_FreeSurface(Texture);}
};

class TWorld 
{
public:
	SDL_Rect Camera;
	TTile* Tile[100][100];
	int TileSize;
	TWorld(int TileSize){this->TileSize=TileSize;}
	~TWorld()
	{
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				delete Tile[i][j];
	}
};