#include <iostream>
#include "MTreeNode.h"

MTreeNode::MTreeNode(MTreeNode* parent)
{
	if (parent != nullptr)
		m_distance = parent->m_distance + 1;
	else
		m_distance = 0;

	m_parent = parent;
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
	return m_child[i];
}

int MTreeNode::distance() const
{
	return m_distance;
}

int MTreeNode::childCount() const
{
	return m_childCount;
}

bool MTreeNode::addChild(int i, int j)
{
	if (this->m_childCount >= 2)
		return false;
	this->m_child[this->m_childCount] = new MTreeNode(this);
	this->m_child[this->m_childCount]->m_i = i;
	this->m_child[this->m_childCount]->m_j = j;
	this->m_childCount++;
	return true;
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
	for (int k = 0; k < this->m_childCount; k++)
	{
		if (this->m_child != nullptr && 
			this->m_child[k]->m_i == i && 
			this->m_child[k]->m_j == j)
			return m_child[k];
	}
	return nullptr;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	auto tree = new MTreeNode(nullptr);
	tree->m_i = i;
	tree->m_j = j;
	return tree;
}