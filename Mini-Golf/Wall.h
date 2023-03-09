#ifndef WALL_H
#define WALL_H

#include <iostream>
#include <vector>

using namespace std;

struct wallsegment
{
	int sx, sy;
	int ex, ey;
};


class Wall
{
private:
	vector<pair<int, int>> WallList;
	int x;
	int y;
	vector <wallsegment> murs;

public:
	Wall(): x(0), y(0), WallList(), murs() {}
	//avoir chaque point du mur
	void addWall(int posX, int posY);
	//avoir le mur au complet
	void ajouterMur(int sx, int sy, int ex, int ey);
	int getsx(int indice)
	{
		return murs[indice].sx;
	}
	int getsy(int indice)
	{
		return murs[indice].sy;
	}
	int getex(int indice)
	{
		return murs[indice].ex;
	}
	int getey(int indice)
	{
		return murs[indice].ey;
	}
	int collisionv2(int posX, int posY);
	bool collision(int posX, int posY);
	void remove();

};

#endif
