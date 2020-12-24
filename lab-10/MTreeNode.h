#ifndef MTREENODE_H
#define MTREENODE_H

class MTreeNode
{
private:
	int m_i = 0;
	int	m_j = 0;
	MTreeNode* m_parent;
	MTreeNode* m_child;
	int m_distance = -1;
	int m_childCount;
	MTreeNode(MTreeNode* parent);
	MTreeNode();

public:
	int i() const;
	int j() const;
	const MTreeNode* parent() const;
	const MTreeNode* child(int i) const;
	int distance() const;
	int childCount() const;
	bool addChild(int i, int j);
	MTreeNode* hasChild(int i, int j);
	static MTreeNode* beginTree(int i, int j);
	MTreeNode* searchNode(const MTreeNode& tree, const int i, const int j);
};

#endif