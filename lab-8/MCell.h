#ifndef MCell_H
#define MCell_H

class MCell
{
private:
	bool m_down = false;
	bool m_right = false;
	MCell();

public:
	bool down();
	bool right();
	friend class Maze;
};

#endif