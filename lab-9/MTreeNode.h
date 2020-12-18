#ifndef MTREENODE_H
#define MTREENODE_H

class MTreeNode
{
private:
	int m_i = 0;
	int m_j = 0;
	MTreeNode* m_parent = nullptr;
	MTreeNode* m_child[2];
	int m_distance = 0;
	int m_childCount = 0;
	MTreeNode(MTreeNode* parent);

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
};

#endif