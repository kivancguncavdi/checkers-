#include <iostream>
#include "board.hpp"

using namespace std;

Board::Board()
{
	for(int row = 0; row < 8; ++row)
		for (int col = 0; col < 8; ++col)
		{
			m_tiles[row][col].setColor((row + col) % 2 == 0 ? Black : White);

			m_tiles[row][col].x = 50 + (50 * col);
			m_tiles[row][col].y = 50 + (50 * row);
			m_tiles[row][col].w = 50;
			m_tiles[row][col].h = 50;
		}
}

void Board::getTileStatus(SDL_Event event)
{
	int x, y;
	x = (event.button.x - 50) / 50;
	y = (event.button.y - 50) / 50;
	
	m_tiles[x][y].Clicked(event);
	cout << "Clicked tile's coordinate is: " << x << ", " << y << endl;
}
