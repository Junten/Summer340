#ifndef __LIST__H__
#define __LIST__H__
#include "Node.h"
using namespace std;

template <class T>
class List{
private:
	Node<T>* headPtr;
	int length;
public:
	List();
	void push(T value);
	T pop();
	void pushEnd(T value);
	T popEnd();
	int getLength();
	T getElement(int element);
	void bubbleSort();
};

#include "List.hxx"
#endif
