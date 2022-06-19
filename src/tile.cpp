#include <iostream>
#include "tile.hpp"

using namespace std;

void Tile::Clicked(SDL_Event event)
{
	if (isClicked())
		m_status = false;
	else
		m_status = true;

	cout << "X axis: " << event.button.x << " Y axis: " << event.button.y << endl;
}