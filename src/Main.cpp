#include "Helper.h"

int fooX = 240, fooY = 90;

int main(int argc, char* args[])
{
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
		bool quit = false;

		SDL_Event e;

		if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }


		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						quit = true;
						break;
					case SDLK_LEFT:
						fooX -= 5;
						break;
					case SDLK_RIGHT:
						fooX += 5;
						break;
					case SDLK_UP:
						fooY -= 5;
						break;
					case SDLK_DOWN:
						fooY += 5;
						break;
					default:
						break;
					}
				}
			}
			
			//Clear screen
			SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			SDL_RenderClear( gRenderer );

			//Render background texture to screen
			gBackgroundTexture.render( 0, 0 );

			//Render Foo' to the screen
			gFooTexture.render( fooX, fooY );

			//Update screen
			SDL_RenderPresent( gRenderer );
		}
    }

    close();

    return 0;
}
