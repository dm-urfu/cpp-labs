#include "SLList.h"
#include <iostream>

using namespace std;

int SLList::getData() const
{
	return m_data;
}

void SLList::setData(int data)
{
	m_data = data;
}

SLList::SLList(int data)
{
	this->m_data = data;
}

SLList::~SLList()
{
	if (this->hasNext())
		delete this->next();
}

SLList* SLList::next() const
{
	return m_nextElem;
}

bool SLList::hasNext() const
{
	return next() != nullptr;
}

SLList* SLList::addElement(int data)
{
	if (!hasNext())
		return m_nextElem = new SLList(data);
	return nullptr;
}

void SLList::removeNext()
{
	if (hasNext())
	{
		SLList* next = this->next();
		SLList* temp = next->m_nextElem;
		next->m_nextElem = nullptr;
		delete next;
		this->m_nextElem = temp;
	}
}

SLList* SLList::beginList(int data)
{
	auto list = new SLList(data);
	return list;
}

