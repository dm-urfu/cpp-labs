#include <iostream>
#include "MCell.h"

MCell::MCell()
{
	this->m_down = false;
	this->m_right = false;
}

bool MCell::right() const
{
	return this->m_right;
}

bool MCell::down() const
{
	return this->m_down;
}