#ifndef SDL_HANDLER_HPP_
#define SDL_HANDLER_HPP_

#include "SDL.h"

class Window {
public:
	Window();
	~Window();
	SDL_Window* getWindow() const { return m_window; };
private:
	SDL_Window* m_window;
	bool m_fullscreen = false;
	int m_flags = SDL_WINDOW_RESIZABLE;
};


class Renderer {
public:
	Renderer(SDL_Window* window);
	~Renderer();
	SDL_Renderer* getRenderer() const { return m_renderer; };
	void renderLine(SDL_Point* points, int pNum, int r, int g, int b, int alpha);
private:
	SDL_Renderer* m_renderer;
};

#endif