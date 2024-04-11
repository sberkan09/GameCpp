#ifndef HELPER_H
#define HELPER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include "Static.h"
#include "LTexture.h"

bool init();
bool loadMedia();
void close();
SDL_Surface* loadSurface(std::string path);
SDL_Texture* loadTexture(std::string path);
void drawRect(SDL_Rect& topLeftViewport);

extern LTexture gFooTexture;
extern LTexture gBackgroundTexture;

#endif
