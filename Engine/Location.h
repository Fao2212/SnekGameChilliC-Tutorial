#pragma once
class Location {
public:
	void Add(const Location& location) {
		Add(location.x,location.y);
	}
	void Add(int _x,int _y) {
		x += _x;
		y += _y;
	}

	bool operator==(const Location& rhs) const 
	{
		return x == rhs.x && y == rhs.y;
	}

	int x, y;
};