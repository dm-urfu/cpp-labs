#ifndef MCELL_H
#define MCELL_H

class MCell
{
private:
	bool m_down = false;
	bool m_right = false;
	MCell();

public:
	bool down() const;
	bool right() const;
	friend class Maze;
};

#endif