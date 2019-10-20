#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

//Direction
enum direction {
	STOP=0,
	LEFT=1,
	UPLEFT=2,
	DOWNLEFT=3,
	RIGHT=4,
	UPRIGHT=5,
	DOWNRIGHT=6,
};

class Ball
{
private:
	int _x, _y;
	//vi tri goc cua x,y
	int literaryX, literaryY;
	direction dir;
public:
	Ball(int, int);
	//quay ve vi tri goc
	void reset();
	void newDirection(direction d);
	void randomDirection();
	int getX();
	int getY();
	direction getDirection();
	void bounce();
};

