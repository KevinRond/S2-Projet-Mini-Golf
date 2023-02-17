#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <time.h>
#include <conio.h>
#include <string>
#include "Ball.h"
#include "Hole.h"
#include "Direction.h"

const int MAX_STRENGTH = 100;

class GameManager 
{
private:
	int width, height;
	int stroke, score;
	bool quit;
	Ball* ball;
	Hole* hole;
public:
	GameManager(int w, int h);
	~GameManager();
	void StrokeUp();
	void StrokeReset();
	void Draw();
	void Input();
	void Logic();
	void Run();
};

#endif
