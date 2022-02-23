#include "Goal.h"

Goal::Goal(std::mt19937& random, const Board& brd, Snake& snake,Color color):
	color(color)
{
	Respawn(random, brd, snake);
}

void Goal::Respawn(std::mt19937& random, const Board& brd, Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0,brd.width-1);
	std::uniform_int_distribution<int> yDist(0,brd.height-1);
	Location newLocation;
	do {
		newLocation.x = xDist(random);
		newLocation.y = yDist(random);
	} while (snake.IsInTile(newLocation));
	loc = newLocation;
}

Location & Goal::GetLocation()
{
	return loc;
}

void Goal::Draw( Board & board)
{
	board.DrawCell(loc,color);
}
