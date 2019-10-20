#pragma once
#include "Bar.h"

class Pong
{
private:
	int width, height;
	int score1, score2;
	char left1, right1, left2, right2;
	bool quit;
	Ball* ball;
	Bar* p1, * p2;
public:
	Pong(int, int);
	~Pong();
	void win(Bar* p);
	void init();
	void input();
	void logic();
	void run();
};

