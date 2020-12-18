#ifndef MAZE_H
#define MAZE_H
#include "MCell.h"

class Maze
{
private:
	MCell* m_field;
	int width;
	int height;

public:
	Maze(int n, int m);
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
	~Maze();
};

#endif