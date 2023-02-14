#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <time.h>
#include <conio.h>
#include "Ball.h"
#include "Hole.h"
#include "Direction.h"

class GameManager 
{
private:
	int width, height;
	int stroke;
	char up, down, left, right, up_right, down_right, up_left, down_left; 
	bool quit;
	Ball* ball;
	Hole* hole;
public:
	GameManager(int w, int h);
	~GameManager();
	void StrokeUp();
	void Draw();
	void Input();
	void Logic();
	void Run();
};

#endif
