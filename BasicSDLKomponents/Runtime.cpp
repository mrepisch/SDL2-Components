
#include "Runtime.h"
#include <stdio.h>
#include <SDL_image.h>
#include "SDLObjectsFactory.h"
#include "GameLoopTimer.h"
#include "stdafx.h"


Runtime::Runtime()
{


}


Runtime::~Runtime()
{
	// void
}

void Runtime::init(int width, int height, const char * windowName)
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	m_SDLwindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_SDLwindow, -1, SDL_RENDERER_ACCELERATED);
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	

	SDLObjectsFactory fac;
	SDL_Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.w = 32;
	rect.h = 32;

	m_sprite = new SpriteAnimation("C:\\Users\\mama\\Documents\\SDL2_Komponents\\testanim.xml",
		fac.createNewTexture("C:\\Users\\mama\\Documents\\SDL2_Komponents\\enemy_goblin.png", m_renderer),
		rect);
	
	m_sprite->setRenderScaled(true);
	
	m_initDone = true;

}

void Runtime::resize(int p_with, int p_height)
{
	SDL_SetWindowSize(m_SDLwindow, p_with, p_height);
}

void Runtime::addIRenderObject(IRenderObject * renderObject)
{
}



void Runtime::start()
{
	const int SCREEN_TICK_PER_FRAME = 1000 / m_fpsCap;
	bool quit = false;
	GameLoopTimer fpsTimer;
	GameLoopTimer capTimer;
	//Event handler
	SDL_Event e;	

	int countedFrames = 0;
	fpsTimer.start();
	while (!quit)
	{

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					m_sprite->startAnim("walk");
					break;
				}
			}
		}
		if (!m_isPaused)
		{
			capTimer.start();
			float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
			if (avgFPS > 2000000)
			{
				avgFPS = 0;
			}
			//Clear screen
			SDL_RenderClear(m_renderer);
			//Fill the surface white

			m_sprite->render(m_renderer);
			//Update the surface
			SDL_RenderPresent(m_renderer);
			++countedFrames;
			int frameTicks = capTimer.getTicks();
			if (frameTicks < SCREEN_TICK_PER_FRAME)
			{
				//Wait remaining time
				SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
			}
		}
	}
}

void Runtime::pause()
{
}

void Runtime::close()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_SDLwindow);
	m_renderer = NULL;
	m_SDLwindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

const bool Runtime::isInitialized()
{
	return m_initDone;
}

void Runtime::setFpsCap(int newFpsCap)
{
	m_fpsCap = newFpsCap;
}
