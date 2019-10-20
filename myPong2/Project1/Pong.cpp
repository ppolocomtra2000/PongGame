#include "Pong.h"

Pong::Pong(int w, int h)
{
	srand(time(NULL));
	quit = false;
	left1 = 'a', right1 = 'd';
	left2 = 'j',right2 = 'l';
	width = w, height = h;
	ball = new Ball(w / 2, h / 2);
	p1 = new Bar(w / 2, 1);
	p2 = new Bar(w / 2, h - 2);
	score1 = score2 = 0;
}

Pong::~Pong()
{
	delete ball, p1, p2;
}

void Pong::win(Bar* p)
{
	if (p == p1)
		score1++;
	else if (p == p2)
		score2++;
	ball->reset();
	p1->reset();
	p2->reset();
}

void Pong::init()
{
	system("cls");
	//top wall
	for (int i = 0; i < width + 2; i++)
		cout << "\xB2";
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int ballx = ball->getX();
			int bally = ball->getY();
			int p1x = p1->getX();
			int p1y = p1->getY();
			int p2x = p2->getX();
			int p2y = p2->getY();
			//left border
			if (j == 0)
				cout << "\xB2";
			//ball
			if (ballx == j && bally == i)
				cout << "o";
			else if (p1x == j && p1y == i)
				cout << "\xDB";//player1
			else if (p2x == j && p2y == i)
				cout << "\xDB";//player2
			else if (p1x +1 == j && p1y  == i)
				cout << "\xDB";//player1
			else if (p1x+2 == j && p1y == i)
				cout << "\xDB";//player1
			else if (p1x +3== j && p1y  == i)
				cout << "\xDB";//player1
			else if (p1x - 1 == j && p1y == i)
				cout << "\xDB";//player1
			else if (p1x - 2 == j && p1y == i)
				cout << "\xDB";//player1
			else if (p1x - 3 == j && p1y == i)
				cout << "\xDB";//player1
			else if (p2x+1 == j && p2y  == i)
				cout << "\xDB";//player2
			else if (p2x +2== j && p2y  == i)
				cout << "\xDB";//player2
			else if (p2x +3== j && p2y  == i)
				cout << "\xDB";//player2
			else if (p2x - 1 == j && p2y == i)
				cout << "\xDB";//player2
			else if (p2x - 2 == j && p2y == i)
				cout << "\xDB";//player2
			else if (p2x - 3 == j && p2y == i)
				cout << "\xDB";//player2
			else
				cout << " ";
			//right border
			if (j == width - 1)
				cout << "\xB2";
		}
		cout << endl;
	}
	//bottom wall
	for (int i = 0; i < width + 2; i++)
		cout << "\xDB";
	cout << endl;

	cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl;
}

void Pong::input()
{
	ball->bounce();
	int ballx = ball->getX();
	int bally = ball->getY();
	int p1x = p1->getX();
	int p1y = p1->getY();
	int p2x = p2->getX();
	int p2y = p2->getY();

	if (_kbhit())
	{
		char ch = _getch();
		if (ch == left1)
			if (p1x > 0)
				p1->moveLeft();
		if (ch == right1)
			if (p1x + 4 < width)
				p1->moveRight();
		if (ch == left2)
			if (p2x > 0)
				p2->moveLeft();
		if (ch == right2)
			if (p2x + 4 < width)
				p2->moveRight();
		if (ch == 'q')
			quit = true;
	}
}

void Pong::logic()
{
	int ballx = ball->getX();
	int bally = ball->getY();
	int p1x = p1->getX();
	int p1y = p1->getY();
	int p2x = p2->getX();
	int p2y = p2->getY();

	//player1 bar
	for (int i = 0; i < 4; i++)
		if (ballx == p1x + i)
			if (bally == p1y + 1)
				ball->newDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

	//player2 bar
	for (int i = 0; i < 4; i++)
	{
		if (ballx == p2x + i)
			if (bally == p2y + 1)
				ball->newDirection(ball->getDirection() == DOWNLEFT ? UPLEFT : UPRIGHT);
	}
	//left border
	if (ballx==0)
		ball->newDirection((direction)((rand() % 3) + 4));
	//right border
	if (ballx == width - 1)
		ball->newDirection((direction)((rand() % 3) + 1));
	if (bally == 0)
		win(p1);
	if (bally == height - 1)
		win(p2);
}

void Pong::run()
{
	while (!quit)
	{
		init();
		input();
		logic();
	}
	//init();
}