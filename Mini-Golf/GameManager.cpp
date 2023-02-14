#include "GameManager.h"
using namespace std;

GameManager::GameManager(int w, int h)
{
	srand(time(NULL));
	quit = false;
	stroke = 0;
	width = w; height = h;
	ball = new Ball(w / 2, h - 2);
	hole = new Hole((w / 2) - 1, 5);
	up = 'w'; down = 's'; left = 'a'; right = 'd';
	up_left = 'q'; up_right = 'e'; 
	down_left = 'z'; down_right = 'c'; 
}

GameManager::~GameManager()
{
	delete ball, hole;
}

void GameManager::StrokeUp()
{
	stroke++;
}

void GameManager::Draw()
{
	//system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "\xB2";
	}
	cout << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int ballx = ball->getX();
			int bally = ball->getY();
			int holex = hole->getX();
			int holey = hole->getY();

			if (i == 0)
			{
				cout << "\xB2";
			}
			if (ballx == i && bally == j)
			{
				cout << "O";
			}
			else if (holex == i && holey == j)
			{
				hole->printHole();
			}
			else
			{
				cout << " ";
			}
			if (i == height - 1)
			{
				cout << "\xB2";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
		cout << "\xb2";
	}
	cout << endl;
}

void GameManager::Input()
{
}

void GameManager::Logic()
{
}

void GameManager::Run()
{
}
