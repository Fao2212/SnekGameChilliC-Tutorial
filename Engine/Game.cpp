/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	board(gfx),
	generator(std::random_device()()),
	snake({ 2,2 }),
	goal(generator,board,snake,Colors::Red),
	obstacle(generator,board,snake,Colors::Gray)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (isGameStarting) {
		if (wnd.kbd.KeyIsPressed('A')) {
			isGameStarting = false;
		}
	}
	else {
		if (!isGameOver) {
			if (wnd.kbd.KeyIsPressed(VK_RIGHT) && delta_location.x == 0) {
				delta_location = { 1,0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT) && delta_location.x == 0) {
				delta_location = { -1,0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_UP) && delta_location.y == 0) {
				delta_location = { 0,-1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN) && delta_location.y == 0) {
				delta_location = { 0,1 };
			}

			if (snakeMovementCounter > snakeMovementRate) {

				if (snake.GetHeadNextLocation(delta_location) == goal.GetLocation()) {
					snake.Grow();
					if (snakeMovementRate > 8)
						snakeMovementRate -= 0.1;
					goal.Respawn(generator, board, snake);
				}
				if (snake.GetHeadNextLocation(delta_location) == obstacle.GetLocation()) {
					isGameOver = true;
				}
				if (snake.HitBodySegment(snake.GetHeadNextLocation(delta_location))) {
					isGameOver = true;
				}
				if (board.IsOutOfBoard(snake.GetHeadNextLocation(delta_location))) {
					isGameOver = true;
				}
				if (!isGameOver) {
					snakeMovementCounter = 0;
					snake.MoveBy(delta_location);
				}

			}
			snakeMovementCounter++;
		}
	}

}

void Game::ComposeFrame()
{
	snake.Draw(board);
	goal.Draw(board);
	obstacle.Draw(board);
	board.DrawBorder(Colors::White);
	if (isGameOver) {
		SpriteCodex::DrawGameOver(((board.width*board.dimension) / 2), ((board.height*board.dimension) / 2) , gfx);
	}
	if (isGameStarting) {
		SpriteCodex::DrawTitle(((board.width*board.dimension) / 2), ((board.height*board.dimension) / 2), gfx);
	}
}
