#include <iostream>
#include "tile.hpp"

using namespace std;

#define TILE_WIDTH (WINDOW_WIDTH / 10)
#define TILE_HEIGHT (WINDOW_HEIGHT / 10)

int Tile::prevX = 0;
int Tile::prevY = 0;
Color Tile::prevTileColor = Black;

void Tile::Clicked(int x, int y, Renderer& renderer)
{
	SDL_Rect rect{ (x + 1)*TILE_WIDTH, (y + 1)*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT };
	SDL_Rect prevRect{ (prevX + 1)*TILE_WIDTH, (prevY + 1)*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT };

	if (isClicked())
		m_status = false;
	else
		m_status = true;

	cout << "X axis: " << x << " Y axis: " << y << " status: " << m_status << endl;

	if (prevX != x || prevY != y) //if clicked a different tile
	{
		if (prevTileColor == White)
			renderer.renderRect(&prevRect, 232, 235, 239, 255);
		else
			renderer.renderRect(&prevRect, 125, 135, 150, 255);

		renderer.renderRect(&rect, 255, 105, 105, 255);
		prevX = x;
		prevY = y;
		prevTileColor = m_tileColor;
	}
	else //if clicked the same tile
	{
		if (m_status)
		{
			renderer.renderRect(&rect, 255, 105, 105, 255);
			prevX = x;
			prevY = y;
			prevTileColor = m_tileColor;
		}
		else
		{
			if (m_tileColor == White)
				renderer.renderRect(&rect, 232, 235, 239, 255);
			else
				renderer.renderRect(&rect, 125, 135, 150, 255);
		}
	}
}