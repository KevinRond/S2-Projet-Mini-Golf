#ifndef WALL_H
#define WALL_H

#include <iostream>
#include <vector>

using namespace std;

#define MAXWALLX 1000
#define MAXWALLY 1000

class Wall
{
private:
	vector<pair<int, int>> WallList;
	int x;
	int y;

public:
	Wall(): x(0), y(0), WallList() {}
	void addWall(int posX, int posY);
	bool collision(int posX, int posY);
	void remove();

};

#endif
