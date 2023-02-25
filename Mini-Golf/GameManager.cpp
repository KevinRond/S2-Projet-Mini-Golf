#include "GameManager.h"
using namespace std;

GameManager::GameManager(int w, int h)
{
	srand(time(NULL));
	quit = false;
	score = 0;
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

void GameManager::StrokeReset()
{
	stroke = 0;
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

	cout << "Nombre de coup: " << stroke << endl;
}

void GameManager::Input()
{
	int input;
	int strength = 0;
	while (1)
	{
		cout << "Enter angle of shot: ";
		cin >> input;
		if (input >= 0 && input <=360)
		{
			ball->setDirection(input);
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

		ball->setStrength(strength);
	}

	// cout << "Strength input is: " << strength << endl;

}

void GameManager::Logic()
{
	int ballx = ball->getX();
	int bally = ball->getY();
	int holex = hole->getX();
	int holey = hole->getY();
	double currentAngle = ball->getDirection();
	ball->Move();

	//Collision with left wall
	if (ballx == 1)
	{
		ball->setDirection(180 - currentAngle);
	}

	//Collision with right wall
	if (ballx == width - 1)
	{
		ball->setDirection(180 - (90 + currentAngle));
	}

	//Collision with top wall
	if (bally == 1)
	{
		if (currentAngle < 90)
		{ 
			ball->setDirection(360 - currentAngle);
		}
		else if (currentAngle > 90)
		{
			ball->setDirection(180 + (180 - currentAngle));
		}
	}

	//Collision with bottom wall
	if (bally == height - 1)
	{
		if (currentAngle < 270)
		{
			ball->setDirection(180 - (90 + currentAngle));
		}
		else if (currentAngle > 270)
		{
			ball->setDirection(180 - currentAngle);
		}
	}

	//Collision with hole
	for (int i = 1; i <= 2; i++)
	{
		if (ballx == holex + 1 || ballx == holex+2)
		{
			if (bally == holey + i)
			{
				score++;
				ball->Reset();
				StrokeReset();
			}
		}
	}
	
}

void GameManager::Run()
{
	while (!quit)
	{
		if (ball->getStrength() == 0)
		{
			Draw();
			Input();
			Logic();
			stroke++;
		}
		else if (ball->getStrength() > 0)
		{
			Draw();
			Logic();
			ball->setStrength(ball->getStrength() - 1);
		}
	}
}
