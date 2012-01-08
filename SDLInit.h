#include "SDL/SDL.h"
#include <string>
#include "SDL/SDL_image.h"

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

SDL_Surface* SDL_screen = NULL;

SDL_Event event;

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
    if(optimizedImage != NULL)
    {
        Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF);
        SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source,
                                 SDL_Surface* destination, SDL_Rect* clip=NULL)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, clip, destination, &offset);
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


