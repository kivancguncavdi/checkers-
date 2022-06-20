#include "SDL.h"
#undef main
#include <iostream>
#include "board.hpp"
#include "SDL_Handler.hpp"
using namespace std;

Board checkersBoard;

bool isRunning;
void handleEvents();
void update();
void render(Renderer& renderer);
void drawBackground(Renderer& renderer);
void drawTiles(Renderer& renderer);

int main() {

	Window window;
	Renderer renderer(window.getWindow());

	//initial render
	render(renderer);
	isRunning = true;

	while (isRunning) {
		handleEvents();
		update();
	}

	return 0;
}

//handles any events that SDL noticed.
void handleEvents() {
	//the only event we'll check is the  SDL_QUIT event.
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEBUTTONDOWN:
		checkersBoard.getTileStatus(event);
	default:
		break;
	}
}

//simple render function
void render(Renderer& renderer) {
	SDL_SetRenderDrawColor(renderer.getRenderer(), 7, 103, 189, 255);
	SDL_RenderClear(renderer.getRenderer());

	//your stuff to render would typically go here.
	//background of the chess board
	drawBackground(renderer);

	//draw and color the tiles
	drawTiles(renderer);
}

//simple update function
void update() {
	//if things could update the code would go in here.
}

void drawBackground(Renderer& renderer) {
	SDL_Rect background;

	background.x = (WINDOW_WIDTH / 10) - 2;
	background.y = (WINDOW_HEIGHT / 10) - 2;
	background.h = ((WINDOW_WIDTH / 10) * 8) + 4;
	background.w = ((WINDOW_HEIGHT / 10) * 8) + 4;

	SDL_RenderDrawRect(renderer.getRenderer(), &background);
	SDL_SetRenderDrawColor(renderer.getRenderer(), 0, 0, 0, 255);
	SDL_RenderFillRect(renderer.getRenderer(), &background);
	SDL_RenderPresent(renderer.getRenderer());
}

void drawTiles(Renderer& renderer) {
	for (int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			auto tile = (checkersBoard.getTile(row, col));
			auto color = (checkersBoard.getTileColor(row, col));

			SDL_RenderDrawRect(renderer.getRenderer(), &tile);

			if (color == Black)
				SDL_SetRenderDrawColor(renderer.getRenderer(), 125, 135, 150, 255);
			else
				SDL_SetRenderDrawColor(renderer.getRenderer(), 232, 235, 239, 255);

			SDL_RenderFillRect(renderer.getRenderer(), &tile);
			SDL_RenderPresent(renderer.getRenderer());
		}
}
