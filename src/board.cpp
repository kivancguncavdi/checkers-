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

void Board::getTileStatus(SDL_Event event, Renderer& renderer)
{
	int x, y;
	x = (event.button.x - (WINDOW_HEIGHT / 10)) / (WINDOW_HEIGHT / 10);
	y = (event.button.y - (WINDOW_HEIGHT / 10)) / (WINDOW_HEIGHT / 10);
	
	if (x < 0 || y < 0 || x > 7 || y > 7)
	{
		cout << "Clicked outside the board!" << endl;
		cout << "Coordinate is: " << event.button.x << ", " << event.button.y << endl;
	}
	else
	{
		m_tiles[x][y].Clicked(x, y, renderer);

		if (m_tiles[x][y].isClicked())
			cout << "Selected tile's coordinate is: " << event.button.x << ", " << event.button.y << endl;
		else
			cout << "De-selected tile's coordinate is: " << event.button.x << ", " << event.button.y << endl;
	}
}
