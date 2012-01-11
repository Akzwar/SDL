#include "SDLInit.h"
#include <cstdio>
TMouse Mouse;
int main(int arg, char* args[])
{   
	Mouse.RBUTTON_PRESSED=false;
	if(init()==false)
		{
			return 1;
		}		

	TWorld* World;
	World = new TWorld(30);
	World->Camera.x=0;
	World->Camera.y=0;
	World->Camera.w=SCREEN_WIDTH;
	World->Camera.h=SCREEN_HEIGHT;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			{
				World->Tile[i][j]=new TTile(i*World->TileSize,j*World->TileSize,World->TileSize-1,World->TileSize-1);
				World->Tile[i][j]->Texture = load_image("1.png");
			}
    bool quit=false;
    while(quit==false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                quit=true;
			if( event.type == SDL_MOUSEBUTTONDOWN )
				{ 
					if( event.button.button == SDL_BUTTON_LEFT )
						Mouse.RBUTTON_PRESSED=true;
				}
			if( event.type == SDL_MOUSEBUTTONUP )
				{
					if( event.button.button == SDL_BUTTON_LEFT )
						Mouse.RBUTTON_PRESSED=false;
				}
			  if( event.type == SDL_MOUSEMOTION )
				{
					if(Mouse.RBUTTON_PRESSED=true)
					{
						Mouse.x = event.motion.x;
						Mouse.y = event.motion.y;
						World->Camera.y=Mouse.y;
						World->Camera.x=Mouse.x;
					}
				}
        }
        Uint8 *keystates = SDL_GetKeyState( NULL );
		if( keystates[ SDLK_DOWN ] )
			World->Camera.y+=1;
		if( keystates[ SDLK_UP ] )
			World->Camera.y-=1;
		if( keystates[ SDLK_RIGHT ] )
			World->Camera.x+=1;
		if( keystates[ SDLK_LEFT ] )
			World->Camera.x-=1;
		SDL_FillRect( SDL_screen, &SDL_screen->clip_rect, SDL_MapRGB( SDL_screen->format, 0xFF, 0xFF, 0xFF ) );
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				{
					if(((World->Tile[i][j]->X2()>(World->Camera.x))&&(World->Tile[i][j]->X1()<(World->Camera.x+World->Camera.w+200)))&&
					((World->Tile[i][j]->Y2()>(World->Camera.y))&&(World->Tile[i][j]->Y1()<(World->Camera.y+World->Camera.h-200))))
					  {
						apply_surface(World->Tile[i][j]->x-World->Camera.x,World->Tile[i][j]->y-World->Camera.y,World->Tile[i][j]->Texture,SDL_screen);
					  }
				}
		//apply_surface(World->Camera->x,World->Camera->y,World->World->Camera->Texture,SDL_screen);
        if(SDL_Flip(SDL_screen) == -1)
            return 1;
    }  
	// delete World;
    SDL_Quit();
    return 0;
}