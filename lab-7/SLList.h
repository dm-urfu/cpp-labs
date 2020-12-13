#ifndef SLLIST_H
#define SLLIST_H

class SLList
{
private:
	SLList* m_nextElem;
	int m_data;
	SLList(int data);

public:
	int getData() const;
	void setData(int data);
	SLList* next() const;
	bool hasNext() const;
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();
	~SLList();
};

#endif // !SLLIST_H
