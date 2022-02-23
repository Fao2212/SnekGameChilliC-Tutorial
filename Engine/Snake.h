#pragma once
#include "Location.h"
#include "Colors.h"
#include <assert.h>
#include "Board.h"

class Snake
{
public:
	Snake(const Location& loc);
	void Grow();
	void Draw(Board& board);
	void MoveBy(const Location& loc);
	Location& GetHeadNextLocation(const Location& location);
	bool IsInTile(const Location& loc);
	bool HitBodySegment(const Location& location);
	Location& GetHeadLocation();

private:
	class Segment {
	public:
		void Follow(Segment& next);
		void MoveBy(const Location& deltaLocation);
		void InitSegment(int nSegment);
		void InitHead(const Location& _location);
		void Draw(Board& board);
		const Location& GetLocation();
	public:
		Location location;
		Color color;
		int nSegment;
	};
private:
	static constexpr int nMaxSegments = 100;
	Segment segments[nMaxSegments] ;
	int nSegments = 1;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr int nColors = 3;
	static constexpr Color bodyColors[nColors] = { Colors::MakeRGB(50,168,84) ,Colors::MakeRGB(84,168,50),Colors::MakeRGB(107,168,50) };
};

