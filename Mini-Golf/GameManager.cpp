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
	/*for (int i = 0; i < width + 2; i++)
	{
		cout << "\xb2";
	}*/
	cout << endl;
}

void GameManager::Input()
{
	string input;
	int strength = 0;
	while (1)
	{
		cout << "Enter direction of shot: ";
		cin >> input;
		if (input == "left")
		{
			ball->changeDirection(LEFT);
			break;
		}
		else if (input == "right")
		{
			ball->changeDirection(RIGHT);
			break;
		}
		else if (input == "up")
		{
			ball->changeDirection(UP);
			break;
		}
		else if (input == "down")
		{
			ball->changeDirection(DOWN);
			break;
		}
		else if (input == "up-left")
		{
			ball->changeDirection(UPLEFT);
			break;
		}
		else if (input == "up-right")
		{
			ball->changeDirection(UPRIGHT);
			break;
		}
		else if (input == "down-left")
		{
			ball->changeDirection(DOWNLEFT);
			break;
		}
		else if (input == "down-right")
		{
			ball->changeDirection(DOWNRIGHT);
			break;
		}
		else
		{
			cout << "Direction input error, please try again" << endl;
		}
	}

	while (strength < 1 || strength > MAX_STRENGTH)
	{
		cout << "Enter strength of stroke (1-"<<MAX_STRENGTH<<"): ";
		cin >> strength;
	
		if (strength < 1 || strength > MAX_STRENGTH)
		{
			cout << "Strength input error, please try again" << endl;
		}

		ball->setBallStrength(strength);
	}

	// cout << "Strength input is: " << strength << endl;

}

void GameManager::Logic()
{
	int ballx = ball->getX();
	int bally = ball->getY();
	int holex = hole->getX();
	int holey = hole->getY();

	
}

void GameManager::Run()
{
}
