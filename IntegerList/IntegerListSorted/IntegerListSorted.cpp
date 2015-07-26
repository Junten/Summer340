//	7/11/2015
//	CSC340, Summer 2015

//	This is the implementation file of the header fiel "SortedIntegerList.h"
//	It contains the construtor, destruction and function method of the class
//	SortedIntegerList, which is contained in the header filer.

#include <iostream>
#include <stdexcept>
#include "IntegerListSorted.h"
using namespace std;

/**
 *	The default constructor, initializes int length to be 0 and headPtr 
 *	to be null pointer 
 */
IntegerListSorted::IntegerListSorted():length(0), headPtr(nullptr) {
}

/**
 *	The destructor, delete all the nodes of the integer list 
 */
IntegerListSorted::~IntegerListSorted() {
	Node<int> *tempPtr = headPtr;
	while (headPtr) {
		headPtr = headPtr->nextPtr;
		delete tempPtr;
		tempPtr = headPtr;
	}
}

/**
 *	The insert() function add an integer to the list in the ascending 
 *	order
 *	
 *	@param int value contains the integer that be added to the sorted 
 *	list
 */
void IntegerListSorted::insert(int value) {
	Node<int> *currPtr = headPtr;
	Node<int> *prevPtr = nullptr;
	Node<int> *newPtr = new Node<int>();
	newPtr->data = value;
	newPtr->nextPtr = nullptr;

	if (headPtr) {
		while (currPtr->nextPtr) {
			if (value > currPtr->data) {
				prevPtr = currPtr;
				currPtr = currPtr->nextPtr;
			} else {
				break;
			}
		}
		if (prevPtr) {
			if (!currPtr->nextPtr) {
				currPtr->nextPtr = newPtr;
			} else {
				prevPtr->nextPtr = newPtr;
				newPtr = currPtr;
			}
		} else {
			headPtr = newPtr;
			newPtr->nextPtr = currPtr;
		}
	} else {
		headPtr = newPtr;
	}
	length++;
}

/**
 *	The getElement() retrieve the integer based on the element postion
 *	in the sorted list
 *	
 *	@param int index contains the integer referring to the index numher
 *
 *	@returns int contain the integer of the sorted list in the specific 
 *	index postion
 */
int IntegerListSorted::getElement(int index) {
	if (index < 0 || index >= length)
		throw out_of_range("Out of Range Error in getElement()");

	Node<int> *currPtr = headPtr;
	for(int i = 0; i < index; i++) {
		currPtr = currPtr->nextPtr;
	}
	return currPtr->data;
}

/**
 *	The valueCount() function get the numbers of the value in the sorted list
 *	
 *	@param int value conataing the value that is searched for number in the 
 *  sorted list
 *
 *	@returns int containing the numbers of integer in the list
 */
int IntegerListSorted::valueCount(int value) {
	int count = 0;
	Node<int> *currPtr = headPtr;
	while (currPtr) {
		if (value == currPtr->data) {
			count++;
		}
		currPtr = currPtr->nextPtr;
	}
	return count;
}

/**
 *	The valueIndex() function retrieve the position index number of sepcific 
 *	value in the sorted list
 *	
 *	@param int value containing the value that is searched in the sorted list
 *
 *	@returns int contais the index number of the specific value in the 
 *	sorted list
 */
int IntegerListSorted::valueIndex(int value) {
	int currentIndex = 0;
	Node<int> *currPtr = headPtr;
	bool valueExist = false;
	while(currPtr->nextPtr) {
		if (value == currPtr->data) {
			valueExist = true;
		 	break;
		}
		currPtr = currPtr->nextPtr;
		currentIndex++;
	}

	if (!valueExist) {
		cout << "\nThe value is not exist in the integer list!";
		return -1;
	} else {
		return currentIndex;
	}
}

/**
 *	The delete() function remove the value of the specific index position 
 *	in the sorted list
 *	
 *	@param int index containing the index number that be removed from the 
 *	sorted list
 */
void IntegerListSorted::remove(int index) {
	if (index < 0 || index >= length)
		throw out_of_range("Out of Range Error in remove()");

	Node<int> *currPtr = headPtr;
	Node<int> *prevPtr = nullptr;
	if (!headPtr->nextPtr) {
		delete headPtr;
		headPtr = nullptr;
	} else {
		for(int i = 0; i < index; i++) {
			prevPtr = currPtr;
			currPtr = currPtr->nextPtr;
		}
		if (index) {
			prevPtr->nextPtr = currPtr->nextPtr;
		}
		else {
			headPtr = currPtr->nextPtr;
		}
		delete currPtr;
	}
	length--;
}	

/**	
 *	The getLength() get the numbers of integers in the list
 *
 *	@returns int containing the numbers of integer in the list
 */
 int IntegerListSorted::getLength() {
 	return length;
 }