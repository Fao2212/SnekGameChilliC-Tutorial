#include "Snake.h"

void Snake::Grow()
{
	segments[nSegments++].InitSegment(nSegments);
}

void Snake::Draw(Board & board)
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(board);
	}
}

void Snake::MoveBy(const Location & loc)
{
	for (int i = nSegments - 1; i > 0; i--) {
		segments[i].Follow(segments[i-1]);
	}
	segments[0].MoveBy(loc);
}

Location & Snake::GetHeadNextLocation(const Location& deltaLocation)
{
	Location nextLocation(segments[0].location);
	nextLocation.Add(deltaLocation);
	return nextLocation;
}

bool Snake::IsInTile(const Location& loc)
{
	for (int i = 0; i < nSegments; i++) {
		if (loc == segments[i].GetLocation()) {
			return true;
		}
	}
	return false;
}

bool Snake::HitBodySegment(const Location & _location)
{
	
	for (int i = 1; i < nSegments - 1; i++) {
		if (segments[i].location == _location) {
			return true;
		}
	}
	return false;
}

Location & Snake::GetHeadLocation()
{
	return segments[0].location;
}

Snake::Snake(const Location & loc)
{
	segments[0].InitHead(loc);
}


void Snake::Segment::Follow(Segment & next)
{
	location = next.location;
}

void Snake::Segment::MoveBy(const Location & deltaLocation)
{
	assert(abs(deltaLocation.x) + abs(deltaLocation.y ) == 1);
	location.Add(deltaLocation.x, deltaLocation.y);
}

void Snake::Segment::InitSegment(int _nSegment)
{
	nSegment = _nSegment;
	color = Snake::bodyColors[nSegment%3];
}

void Snake::Segment::Draw(Board& board)
{
	board.DrawCell(location,color);
}

const Location & Snake::Segment::GetLocation()
{
	return location;
}

void Snake::Segment::InitHead(const Location& _location)
{
	location = _location;
	color = Snake::headColor;
}
