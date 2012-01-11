<<<<<<< HEAD
#include "tiling.h"
#include "SDL/SDL_image.h"
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;
const int SCREEN_BPP = 32;

struct TMouse
{
	bool RBUTTON_PRESSED;
	int x;
	int y;
};
=======
#include "SDL/SDL.h"
#include <string>
#include "SDL/SDL_image.h"

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;
>>>>>>> 513ee2e6de5ebb2ab3760918f4926f200d205578

SDL_Surface* SDL_screen = NULL;

SDL_Event event;

<<<<<<< HEAD


bool init()
{
	
    SDL_screen = SDL_SetVideoMode(SCREEN_HEIGHT,SCREEN_WIDTH,SCREEN_BPP,SDL_SWSURFACE);
    if(SDL_screen == NULL)
        return 1;
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
        return false;
    return true;
} 

=======
>>>>>>> 513ee2e6de5ebb2ab3760918f4926f200d205578
SDL_Surface* load_image(std::string filename)
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str());
    if(loadedImage!=NULL)
    {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);
    }
<<<<<<< HEAD
    // if(optimizedImage != NULL)
    // {
        // Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF);
        // SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    // }
=======
    if(optimizedImage != NULL)
    {
        Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF);
        SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }
>>>>>>> 513ee2e6de5ebb2ab3760918f4926f200d205578
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source,
                                 SDL_Surface* destination, SDL_Rect* clip=NULL)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, clip, destination, &offset);
<<<<<<< HEAD
}
=======
}

bool init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
        return false;
    SDL_screen = SDL_SetVideoMode(SCREEN_HEIGHT,SCREEN_WIDTH,SCREEN_BPP,SDL_SWSURFACE);
    if(SDL_screen == NULL)
        return false;
    return true;
}


>>>>>>> 513ee2e6de5ebb2ab3760918f4926f200d205578
