#include <iostream>
#include "tile.hpp"

using namespace std;

#define TILE_WIDTH (WINDOW_WIDTH / 10)
#define TILE_HEIGHT (WINDOW_HEIGHT / 10)

void Tile::Clicked(int x, int y, Renderer renderer)
{
	if (isClicked())
		m_status = false;
	else
		m_status = true;

	cout << "X axis: " << x << " Y axis: " << y << endl;

	SDL_Point selIndicator[2] = { {(x + 1)*TILE_WIDTH, (y + 1)*TILE_HEIGHT}, {(x + 2)*TILE_WIDTH, (y + 1)*TILE_HEIGHT} };
	renderer.renderLine(selIndicator, 2, 255, 0, 0, 255);
}