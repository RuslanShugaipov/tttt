#pragma once
#include "Iterator.h"
#include "dualList.h"


class BinaryHeap
{
protected:
	int MaxSize = 10;
	int* root;
	int HeapSize;
	void heapify(int, int);
	void siftUP(int);
	void siftDown(int);
public:
	BinaryHeap();
	~BinaryHeap();
	bool contains(int);
	void insert(int);
	void remove(int);
	void out();

	//Dft_iterator
	Iterator* create_dft_iterator();
	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int);
		int next(BinaryHeap*) override;
		bool has_next(BinaryHeap*) override;
	private:
		int index;
		dualList stk;
	};

	//Bft_iterator
	Iterator* create_bft_iterator();
	class bft_iterator :public Iterator
	{
	public:
		bft_iterator(int);
		int next(BinaryHeap*) override;
		bool has_next(BinaryHeap*) override;
	private:
		int index;
	};
};