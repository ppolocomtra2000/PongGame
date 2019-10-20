#include "Bar.h"

Bar::Bar(int x, int y)
{
	this->_x = x;
	this->_y = y;
	this->literaryX = x;
	this->literaryY = y;
}

void Bar::reset()
{
	this->_x = literaryX;
	this->_y = literaryY;
}

int Bar::getX() { return this->_x; }
int Bar::getY() { return this->_y; }
void Bar::moveLeft() { this->_x++; }
void Bar::moveRight() { this->_x--; }