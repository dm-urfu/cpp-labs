#include "Maze.h"
#include "MTreeNode.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <stack>

using namespace std;

void printTree(int n, int m, int** tree)
{
	const char* space;
	if (n * m <= 100) space = "%3d";
	else  space = "%4d";

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf(space, tree[i][j]);
		printf("\n");
	}
}


void getWeights(MTreeNode* tree, int width, int height)
{
	int max = -1;
	int sum = 0;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			auto node = *(tree->searchNode(*tree, y, x));
			int dist = node.distance();
			sum = sum + dist;
			if (max < dist)
				max = dist;
		}
	cout << endl << "max weight: " << max << endl;
	cout << "average weight: " << (sum / (width * height)) << endl;
}


void buildFullMaze(Maze& iMaze, MTreeNode& tree)
{
	map <tuple<int, int>, bool> visited;
	stack <tuple<int, int>> points;

	int n = iMaze.width();
	int m = iMaze.height();

	int i = tree.i(), j = tree.j();
	auto node = &tree;

	int** fullTree = new int* [m];
	for (int k = 0; k <= m; k++)
		fullTree[k] = new int[n];

	while (true)
	{
		if (visited.size() == n * m)
			break;

		fullTree[i][j] = node->distance();

		visited[tuple<int, int>(j, i)] = true;

		vector<tuple<int, int>> unvisited;
		for (int y = -1; y <= 1; y++)
			for (int x = -1; x <= 1; x++)
				if (((x == -1 && y == 0) || (x == 1 && y == 0) || (x == 0 && y == 1) || (x == 0 && y == -1)) &&
					j + x >= 0 && i + y >= 0 && j + x < n && i + y < m && visited.count(tuple<int, int>(j + x, i + y)) == 0)
					unvisited.push_back(tuple<int, int>(j + x, i + y));

		if (unvisited.size() == 0)
		{
			tuple<int, int> point = points.top();
			points.pop();
			j = get<0>(point);
			i = get<1>(point);
			node = (MTreeNode*)node->parent();
			continue;
		}

		auto rnd = unvisited[rand() % unvisited.size()];

		iMaze.makeConnection(i, j, get<1>(rnd), get<0>(rnd));
		points.push(tuple<int, int>(j, i));
		j = get<0>(rnd);
		i = get<1>(rnd);

		node->addChild(i, j);
		node = node->hasChild(i, j);
	}

	(&iMaze)->printMaze();
	cout << endl;
	printTree(n, m, fullTree);
}

int main()
{
	srand(time(0));

	int width, height;
	cout << "width: ";
	cin >> width;
	cout << "height: ";
	cin >> height;

	int i = rand() % height, j;

	if (i == 0 || i == height - 1) 
		j = rand() % width;
	else if (rand() % 2 == 0)
		j = 0;
	else 
		j = width - 1;

	Maze* iMaze = new Maze(width, height);
	MTreeNode* tree = MTreeNode::beginTree(i, j);
	buildFullMaze(*iMaze, *tree);
	getWeights(tree, width, height);
}