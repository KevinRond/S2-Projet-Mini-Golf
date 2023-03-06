#include "Wall.h"


void Wall::addWall(int posX, int posY)
{
	WallList.push_back(make_pair(posX, posY));
}

bool Wall::collision(int posX, int posY)
{
	for (const auto& posWall : WallList)
	{
		if (posWall.first == posX && posWall.second == posY)
		{
			return true;
		}
	}
	return false;
}

void Wall::remove()
{
	WallList.clear();
}