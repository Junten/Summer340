#ifndef __INTEGERLISTARRAY__H__
#define __INTEGERLISTARRAY__H__

class IntegerListArray{
private:
	int *list;
	int length;
public:
	IntegerListArray();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
	void bubbleSort();
};

#endif
