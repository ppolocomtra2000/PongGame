#pragma once
#include "Ball.h"

class Bar
{
private:
	int _x, _y;
	int literaryX, literaryY;
public:
	Bar(int, int);
	void reset();
	int getX();
	int getY();
	void moveLeft();
	void moveRight();
};

