#include "Maze.h"
#include <iostream>

int main()
{
	Maze* maze = new Maze(5, 5);

	for (int i = 0; i < 5; i++)
	{
		maze->makeConnection(i - 1, i, i, i);
		maze->makeConnection(i, i, i, i + 1);
	}

	maze->printMaze();
}