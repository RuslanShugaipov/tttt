#pragma once
class BinaryHeap;

class Iterator
{
public:
	virtual int next(BinaryHeap*)=0;
	virtual bool has_next(BinaryHeap*)=0;
};