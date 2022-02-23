#include "Board.h"

void Board::DrawCell(const Location & _loc, Color color)
{
	int x = _loc.x*dimension+marginLeft;
	int y = _loc.y*dimension+marginTop;
	gfx.DrawRectangle(boardPadding+x, boardPadding + y,x+dimension,y+dimension,color);
}

Board::Board(Graphics & _gfx):gfx(_gfx)
{

}

bool Board::IsOutOfBoard(const Location & _loc)
{
	return _loc.x >= width || _loc.x < 0 || _loc.y < 0 || _loc.y >= height;
}

void Board::DrawBorder(Color color) {
	int _width = (width * dimension) + marginLeft;
	int _height = (height * dimension) + marginTop;
	for (int i = marginLeft; i < _width; i++) {
		for (int j = marginTop; j < _height; j++) {
			if (i > marginLeft && i < _width-1 && j > marginTop ) {
				j += _height-marginTop;
			}
			gfx.PutPixel(i, j, color);
		}
	}
}