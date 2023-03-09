#include "Wall.h"


void Wall::addWall(int posX, int posY)
{
	WallList.push_back(make_pair(posX, posY));
}

void Wall::ajouterMur(int sx, int sy, int ex, int ey)
{
	wallsegment mur = { sx,sy,ex,ey };
	murs.push_back(mur);
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

int Wall::collisionv2(int posX, int posY)
{
	for (int i = 0; i < murs.size();i++)
	{
		const auto& mur = murs[i];
		if (posX >= mur.sx && posX <= mur.ex && posY >= mur.sy && posY <= mur.ey)
		{
			return i;
		}

	}
	return -1;
}

void Wall::remove()
{
	WallList.clear();
	murs.clear();
}