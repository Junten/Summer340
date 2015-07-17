// 6/26/2015
// CSC 340, Summber 2015

// This is the implementation file of the header file "IntegerList.h".
// It contains the constructor and functions method of the class IntegerList,
// which is in the header file.

#include <iostream>
#include "IntegerList.h"
using namespace std;

/** 
 * 	The default constructor, initializes int <b>length</b> to be 0 and the
 *linked list first node <b>first</b> to 
 * 	be null pointer. 
 */
IntegerList::IntegerList():length(0) {
	headPtr = new Node();
	headPtr = nullptr;
}

/** 
 * 	The push() function add an integer to the beginning of the list.
 *
 *  @param int <b>value</b> contains the integer that be added to the lsit.
 * 
 */
void IntegerList::push(int value) {
	length++;
	Node *newPtr = new Node();
	newPtr->data = value;
	newPtr->nextPtr = headPtr;
	headPtr = newPtr;
}

/**
 * 	The pop() function removes and retrieved the integer from the beginning of 
 *	the list
 *
 * 	@returns int <b>popValue</b> contains the integer that is removed from the 
 *	list
 */
int IntegerList::pop(){
	if (length == 0) {
		cout << "Error! The list is empty!" << endl;
		return 0;
	}
	
	length--;
	int popValue = 0;
	if (length == 0) {
		delete headPtr;
	} else {
		Node *tempPtr = headPtr;
		popValue = tempPtr->data;
		headPtr = tempPtr->nextPtr;
		delete tempPtr;
	}
	return popValue;
}

/**	
 *  The pushEnd() function add an integer at the end of the list
 *
 *	@param int <b>value</b> contains the integer that is adding to the list
 */
void IntegerList::pushEnd(int value) {
	length++;
	Node *newPtr = new Node();
	newPtr->data = value;
	newPtr->nextPtr = nullptr;
	Node *currPtr = headPtr;

	while (currPtr->nextPtr) {
		currPtr = currPtr->nextPtr;
	}
	currPtr->nextPtr = newPtr; 
}

/**	
 *	The popEnd() retrieve and remove the intgegen from the end of the list
 *
 *	@returns int contaibs the integer that is removed from the list
 */
int IntegerList::popEnd() {
	if (length == 0) {
		cout << "Error! The list is empty!" << endl;
		return 0;
	}

	length--;
	int popValue = 0;
	if (length == 0) {
		delete headPtr;
	} else {
		Node *currPtr = headPtr;
		Node *prePtr = nullptr;
		while (currPtr->nextPtr) {
			prePtr = currPtr;
			currPtr = currPtr->nextPtr;
		}	
		prePtr->nextPtr = nullptr;
		popValue = currPtr->data;
		delete currPtr;	           
	}
	return 0;
}

/**	
 *	The getLength() get the numbers of integers in the list
 *
 *	@returns int containing the numbers of integer in the list
 */
int IntegerList::getLength() {
	return length;
}

/**	
 *	The getElement() get the integer based on the element position in the list
 *
 *	@param int <b>element</b> contains the integer referring to the index number
 *
 *	@returns int containing the integer of the list in the specific element
 *  position
 */
int IntegerList::getElement(int element){
	Node *currPtr = headPtr;
	for(int i = 0; i < element; i++) {
		currPtr = currPtr->nextPtr;
	}
	return currPtr->data;
}

/**
 *	The bubbleSort() arrange the integer list in ascending order
 */
void IntegerList::bubbleSort() {
	Node *currPtr = nullptr;
	Node *p;
	Node *p2;
	Node *p1 = new Node();
	p1->nextPtr = headPtr;
	headPtr = p1;

	for (currPtr = nullptr; currPtr != headPtr; currPtr = p) {
		for (p = p1 = headPtr; p1->nextPtr->nextPtr != currPtr; p1 = p1->nextPtr) {
			if (p1->nextPtr->data > p1->nextPtr->nextPtr->data) {
				p2 = p1->nextPtr->nextPtr;
				p1->nextPtr->nextPtr = p2->nextPtr;
				p2->nextPtr = p1->nextPtr;
				p1->nextPtr = p2;
				p = p1->nextPtr->nextPtr;
			}
		}
	}

	p1 = headPtr;
	headPtr = headPtr->nextPtr;
	delete p1;
	p1 = nullptr;
}


int main() {
	IntegerList list;
	list.push(1);
	list.push(2);
	list.push(3);
	for (int i = 0; i < 3; i++) {
		cout << i << ": " << list.getElement(i) << endl;
	}
	cout << "Previous size: " << list.getLength() << endl;
	cout << "list[1]: " << list.pop() << endl;
	cout << "after size: " << list.getLength() << endl;
	list.push(3);
	list.bubbleSort();
	for (int i = 0; i < 3; i++) {
		cout << i << ": " << list.getElement(i) << endl;
	}
	return 0;
}

