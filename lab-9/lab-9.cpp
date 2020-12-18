#include "Maze.h"
#include "MTreeNode.h"
#include <iostream>

using namespace std;

int main()
{
	Maze* maze = new Maze(5, 5);
	MTreeNode* tree = MTreeNode::beginTree(0, 0);

	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = 0; j < 5 - i - 1; j++)
		{
			maze->makeConnection(i, i + j, i, i + j + 1);
			maze->makeConnection(i + j, i, i + j + 1, i);
		}
		maze->makeConnection(i, i + 1, i + 1, i + 1);
	}

	maze->removeConnection(0, 0, 0, 1);
	maze->printMaze();
	cout << endl;

	int weights[6][6];
	auto iterate = tree;
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			if (i == k) {
				auto prev = iterate;
				weights[i][k] = iterate->distance();
				for (int j = k + 1; j < 6; j++) {
					iterate->addChild(i, j);
					iterate = iterate->hasChild(i, j);
					weights[i][j] = iterate->distance();
				}
				iterate = prev;
				for (int j = i + 1; j < 6; j++) {
					iterate->addChild(j, k);
					iterate = iterate->hasChild(j, k);
					weights[j][k] = iterate->distance();
				}
				iterate = prev;
				iterate = iterate->hasChild(i, k + 1);
				iterate->addChild(i + 1, k + 1);
				weights[i + 1][k + 1] = iterate->distance();
				iterate = iterate->hasChild(i + 1, k + 1);
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			cout << weights[i][k] << " ";
		}
		cout << endl;
	}
}