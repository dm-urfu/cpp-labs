#include <iostream>
#include <algorithm>
#include "Maze.h"

using namespace std;

Maze::Maze(int n, int m)
{
	width = n;
	height = m;
	m_field = new MCell[n * m];
}

const MCell& Maze::cell(int i, int j) const
{
	return m_field[i * width + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (((abs(i1 - i2) + abs(j1 - j2)) != 1) || i1 < 0 || i2 < 0 || j1 < 0 || j2 < 0)
		return false;

	MCell cell;
	if (i1 != i2)
	{
		if (i1 > i2)
			cell = this->cell(i2, j2);
		else
			cell = this->cell(i1, j1);
		return cell.down();
	}
	else
	{
		if (j1 > j2)
			cell = this->cell(i2, j2);
		else
			cell = this->cell(i1, j1);
		return cell.right();
	}
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (i1 != i2 && j1 != j2 || ((abs(i1 - i2) + abs(j1 - j2)) != 1))
		return false;

	if (i1 == i2)
		m_field[i1 * width + min(j1, j2)].m_right = true;
	else
		m_field[min(i1, i2) * width + j1].m_down = true;
		
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (i1 != i2 && j1 != j2 || ((abs(i1 - i2) + abs(j1 - j2)) != 1))
		return false;

	if (i1 == i2)
		m_field[i1 * width + min(j1, j2)].m_right = false;
	else
		m_field[min(i1, i2) * width + j1].m_down = false;

	return true;
}


void Maze::printMaze() {
	bool up = false;
	bool right = false;
	bool down = false;
	bool left = false;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (hasConnection(i, j, i - 1, j))
				up = true;
			if (hasConnection(i, j, i, j + 1))
				right = true;
			if (hasConnection(i, j, i + 1, j))
				down = true;
			if (hasConnection(i, j, i, j - 1))
				left = true;

			if (up && left && right)
				cout << (char)193;
			else if (down && right && left)
				cout << (char)194;
			else if (up && down && right)
				cout << (char)195;
			else if (up && down && left)
				cout << (char)180;
			else if (up && down)
				cout << (char)179;
			else if (left && down)
				cout << (char)191;
			else if (up && right)
				cout << (char)192;
			else if (left && right)
				cout << (char)196;
			else if (left && up)
				cout << (char)217;
			else if (right && down)
				cout << (char)218;
			else if (left && right && up && down)
				cout << (char)197; 
			else
				cout << (char)48;

			left = false;
			up = false;
			right = false;
			down = false;
		}

		cout << endl;
	}
};

Maze::~Maze()
{
	for (int i = 0; i < width * height; i++)
		delete& m_field[i];
}