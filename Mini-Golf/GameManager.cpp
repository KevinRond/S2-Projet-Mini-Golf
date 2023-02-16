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
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "\xB2";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int ballx = ball->getX();
			int bally = ball->getY();
			int holex = hole->getX();
			int holey = hole->getY();

			if (j == 0)
			{
				cout << "\xB2";
			}
			if (ballx == j && bally == i)
			{
				cout << "O";
			}
			else if (holey == i || holey + 3 == i)
			{
				if (j == holex + 1 || j == holex + 2)
				{
					cout << "#";
				}
				else
				{
					cout << " ";
				}
			}
			else if (holey + 1 == i || holey + 2 == i)
			{
				if (j == holex || j == holex + 3)
				{
					cout << "#";
				}
				else
				{
					cout << " ";
				}
			}
			else
			{
				cout << " ";
			}
			if (j == width - 1)
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
