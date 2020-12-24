#include "MTreeNode.h"
#include <map>

using namespace std;

MTreeNode::MTreeNode() {}

MTreeNode::MTreeNode(MTreeNode* parent)
{
	m_parent = parent;
	m_child = new MTreeNode[3];
	if (parent != nullptr)
		m_distance = parent->m_distance + 1;
}

int MTreeNode::i() const
{
	return m_i;
}

int MTreeNode::j() const
{
	return m_j;
}

const MTreeNode* MTreeNode::parent() const
{
	return m_parent;
}

const MTreeNode* MTreeNode::child(int i) const
{
	return &(m_child[i]);
}

int MTreeNode::distance() const
{
	return m_distance;
}

int MTreeNode::childCount() const
{
	int result = 0;
	for (int i = 0; i < 3; i++)
		if (m_child[i].m_distance != -1)
			result = result + 1;
	return result;
}

bool MTreeNode::addChild(int i, int j)
{
	MTreeNode child = MTreeNode(this);
	child.m_i = i;
	child.m_j = j;
	m_child[childCount()] = child;
	return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
	for (int k = 0; k < 3; k++)
	{
		MTreeNode* child = &m_child[k];
		if (child->m_i == i && child->m_j == j)
			return child;
	}
	return this;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	MTreeNode* tree = new MTreeNode(nullptr);
	tree->m_j = j;
	tree->m_i = i;
	tree->m_distance = 0;
	return tree;
}

MTreeNode* MTreeNode::searchNode(const MTreeNode& tree, const int i, const int j)
{
	auto currentNode = tree;

	if (i == tree.m_i && j == tree.m_j)
		return &currentNode;

	map <tuple<int, int>, int> visited;

	int k = 0;
	while (true)
	{
		if (currentNode.hasChild(i, j) != &currentNode)
			return currentNode.hasChild(i, j);
		if (currentNode.childCount() > k && visited[tuple<int, int>(currentNode.m_i, currentNode.m_j)] < 2)
		{
			visited[tuple<int, int>(currentNode.m_i, currentNode.m_j)] = visited[tuple<int, int>(currentNode.m_i, currentNode.m_j)] + 1;
			currentNode = *currentNode.child(k);
			k = 0;
			continue;
		}
		else
		{
			currentNode = *currentNode.parent();
			k = 1;
		}
	}
}
