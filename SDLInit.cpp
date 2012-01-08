#include "SDLInit.h"

int main(int arg, char* args[])
{   
    bool quit=false;
    if(init()==false)
    {
        return 1;
    }
    
    while(quit==false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                quit=true;
        }
        Uint8 *keystates = SDL_GetKeyState( NULL );
	
        if(SDL_Flip(SDL_screen) == -1)
            return 1;
    }  
    SDL_Quit();
    return 0;
}