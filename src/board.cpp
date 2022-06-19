#include <iostream>
#include "board.hpp"

using namespace std;

Board::Board()
{
	for(int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			m_tiles[row][col].setColor((row + col) % 2 == 0 ? Black : White);

			m_tiles[row][col].x = (WINDOW_WIDTH / 10) + ((WINDOW_WIDTH / 10) * col);
			m_tiles[row][col].y = (WINDOW_HEIGHT / 10) + ((WINDOW_HEIGHT / 10) * row);
			m_tiles[row][col].w = (WINDOW_WIDTH / 10);
			m_tiles[row][col].h = (WINDOW_HEIGHT / 10);
		}
}

void Board::getTileStatus(SDL_Event event)
{
	int x, y;
	x = (event.button.x - (WINDOW_HEIGHT / 10)) / (WINDOW_HEIGHT / 10);
	y = (event.button.y - (WINDOW_HEIGHT / 10)) / (WINDOW_HEIGHT / 10);
	
	m_tiles[x][y].Clicked(event);
	cout << "Clicked tile's coordinate is: " << x << ", " << y << endl;
}
