#pragma once
#include "Location.h"
#include "Colors.h"
#include "Graphics.h"

class Board
{

public:
	static constexpr int marginTop = 40;
	static constexpr int marginLeft = 40;
	void DrawCell(const Location& _loc,Color color);
	Board(Graphics& _gfx);
	static constexpr int width = 15;//number of rows
	static constexpr int height = 15;//Number of columns
	static constexpr int dimension = 30;//Cell size
	bool IsOutOfBoard(const Location& _loc);
	void DrawBorder(Color color);
private:
	static constexpr int boardPadding = 10;
	Graphics& gfx;


};

