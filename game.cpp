#include "SDL.h"
#undef main
#include <iostream>
#include "board.hpp"
using namespace std;

//don't do this, this is just an example
SDL_Renderer* renderer;
SDL_Window* window;
Board chessBoard;

bool isRunning;
bool fullscreen;
void handleEvents();
void update();
void render();
void drawBackground();
void drawTiles();
unsigned int score = 0;


//please don't put all your code in main like I did.
int main() {

	fullscreen = false;
	int flags = 0;
	flags = SDL_WINDOW_RESIZABLE;
	if (fullscreen) {
		flags = flags | SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";

		window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, flags);
		if (window) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(window, 100, 100);
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 1, 1, 1, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			isRunning = true;
		}
	}

	render();

	while (isRunning) {
		handleEvents();
		update();
		//render();
	}

	//frees memory associated with renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);	//error here
	SDL_Quit();


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
		chessBoard.getTileStatus(event);
		if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
			score--;
	default:
		break;
	}
}

//simple render function
void render() {
	SDL_SetRenderDrawColor(renderer, 7, 103, 189, 255);
	SDL_RenderClear(renderer);

	//your stuff to render would typically go here.
	//background of the chess board
	drawBackground();

	//draw and color the tiles
	drawTiles();
}

//simple update function
void update() {
	//if things could update the code would go in here.
}

void drawBackground() {
	SDL_Rect background;

	background.x = 48;
	background.y = 48;
	background.h = 404;
	background.w = 404;

	SDL_RenderDrawRect(renderer, &background);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &background);
	SDL_RenderPresent(renderer);
}

void drawTiles() {
	for (int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			auto tile = (chessBoard.getTile(row, col));
			auto color = (chessBoard.getTileColor(row, col));

			SDL_RenderDrawRect(renderer, &tile);

			if (color == Black)
				SDL_SetRenderDrawColor(renderer, 125, 135, 150, 255);
			else
				SDL_SetRenderDrawColor(renderer, 232, 235, 239, 255);

			SDL_RenderFillRect(renderer, &tile);
			SDL_RenderPresent(renderer);
		}
}
