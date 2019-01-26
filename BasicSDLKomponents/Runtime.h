#pragma once
#include "Export.h"
#include <memory>
#include "SDL.h"
#include "SpriteAnimation.h"
#include "Camera.h"
class BASIC_KOMPONENT_API Runtime
{
public:
	Runtime();
	~Runtime();
	void init(int width, int height, const char* windowName);
	void resize(int p_with, int p_height);
	void addIRenderObject(IRenderObject* renderObject);
	void addCamera(Camera* cam);
	Camera* getCamera();
	SDL_Renderer* getRenderer();
	void start();
	void pause();
	void close();
	const bool isInitialized();
	void setFpsCap(int newFpsCap);
private:

	SDL_Window* m_SDLwindow;
	SDL_Renderer* m_renderer;
	bool m_initDone = false;
	bool m_isPaused = false;
	std::vector<IRenderObject*>m_renderObjects;
	int m_fpsCap = 10;
	Camera* m_camera = nullptr;
};

