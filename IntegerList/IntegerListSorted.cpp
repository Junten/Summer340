//	The implementation file of the header fiel "IntegerListSorted.h"

#include <stdexcept>
#include <iostream>
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
 *	The insert() function adds an integer to the list in the ascending 
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
 *	The getElement() retrieve the integer based on the value's postion in the 
 *	sorted list
 *	
 *	@param int index contains the index number refer to the value in the list
 *
 *	@returns int contain the integer of the sorted list in the specific 
 *	index postion
 */
int IntegerListSorted::getElement(int index) {
	if (index < 0 || index >= length) {
		throw out_of_range("Out of Range Error in getElement()");
	}

	Node<int> *currPtr = headPtr;
	for(int i = 0; i < index; i++) {
		currPtr = currPtr->nextPtr;
	}
	return currPtr->data;
}

/**
 *	The valueCount() function getS the numbers of the value in the sorted list
 *	
 *	@param int value conatains the value that is searched for index number in 
 *	the sorted list
 *
 *	@returns int contains the numbers of value in the sorted list
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
 *	The valueIndex() function retrieves the index number of sepcific value in 
 *	the sorted list
 *	
 *	@param int value contains the value that is searched in the sorted list
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
 *	@param int index contains the index number for the postion of value that 
 *	is removed from the sorted list
 */
void IntegerListSorted::remove(int index) {
	if (index < 0 || index >= length) {
		throw out_of_range("Out of Range Error in remove()");
	}

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
 *	The getLength() get the numbers of values in the list
 *
 *	@returns int contains the numbers of value in the list
 */
 int IntegerListSorted::getLength() {
 	return length;
 }