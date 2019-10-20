#include "Ball.h"

Ball::Ball(int x, int y)
{
	this->_x = x;
	this->_y = y;
	this->literaryX = x;
	this->literaryY = y;
	this->dir = STOP;
}

void Ball::reset()
{
	_x = literaryX;
	_y = literaryY;
	dir = STOP;
}

void Ball::newDirection(direction d)
{
	this->dir = d;
}

void Ball::randomDirection()
{
	this->dir = (direction)((rand() % 6) + 1);
}

int Ball::getX() { return this->_x; }
int Ball::getY() { return this->_y; }
direction Ball::getDirection() { return this->dir; }

void Ball::bounce()
{
	switch (this->dir)
	{
	case STOP:
		break;
	case LEFT:
		_x--;
		break;
	case UPLEFT:
		_x--;
		_y--;
		break;
	case DOWNLEFT:
		_x--;
		_y++;
		break;
	case RIGHT:
		_x++;
		break;
	case UPRIGHT:
		_x++;
		_y--;
		break;
	case DOWNRIGHT:
		_x++;
		_y++;
		break;
	default:
		break;
	}
}