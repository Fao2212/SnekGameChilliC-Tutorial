#pragma once
#include "Location.h"
#include "Snake.h"
#include "Board.h"
#include <random>
class Goal
{
public:
	Goal(std::mt19937& random, const Board& brd,  Snake& snake,Color color);
	void Respawn(std::mt19937& random, const Board& brd, Snake& snake);
	Location& GetLocation();
	void Draw( Board& board);

private:
	Location loc;
	Color color;
};

