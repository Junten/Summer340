//	7/11/2015
//	CSC340, Summer 2015
//	Writen By: Junteng Tan
//	This is the implementation file of the header fiel "SortedIntegerList.h"
//	It contains the construtor, destruction and function method of the class
//	SortedIntegerList, which is contained in the header filer.

#include <iostream>
#include <stdexcept>
#include "SortedIntegerList.h"
using namespace std;

/**
 *	The default constructor, initializes int length to be 0 and headPtr 
 *	to be null pointer 
 */
SortedIntegerList::SortedIntegerList():length(0) {
	headPtr = new Node();
	headPtr = nullptr;
}

/**
 *	The destructor, delete all the nodes of the integer list 
 */
SortedIntegerList::~SortedIntegerList() {
 	Node *currPtr = headPtr;
 	Node *tempPtr = headPtr;
 	while (currPtr->nextPtr) {
 		currPtr = currPtr->nextPtr;
 		delete tempPtr;
 		tempPtr = currPtr;
 	}
}

/**
 *	The insert() function add an integer to the list in the ascending 
 *	order
 *	
 *	@param int value contains the integer that be added to the sorted 
 *	list
 */
void SortedIntegerList::insert(int value) {
	Node *currPtr = headPtr;
	Node *prevPtr = nullptr;
	Node *newPtr = new Node();
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
int SortedIntegerList::getElement(int index) {
	Node *currPtr = headPtr;
	int currentIndex = 0;

	while (index != currentIndex) {
		currPtr = currPtr->nextPtr;
		currentIndex++;
	}
	return currPtr->data;
}

/**
 *	The getLength() function get the numbers of integers in the sorted list
 *	
 *	@returns int containing the numbers of integer in the list
 */
int SortedIntegerList::getLength() {
	return length;
}

/**
 *	The valueIndex() function retrieve the position index number of sepcific 
 *	value in the sorted list
 *	
 *	@param int value containing the value that be searched in the sorted list
 *
 *	@returns int contais the index number of the specific value in the 
 *	sorted list
 */
int SortedIntegerList::valueIndex(int value) {
	int currentIndex = 0;
	Node *currPtr = headPtr;
	while(currPtr->nextPtr) {
		if (value == currPtr->data)
			break;
		else {
			currPtr = currPtr->nextPtr;
			currPtr++;
		}
	}

	if (currentIndex == length - 1) {
		cout << "The value(" << value << ") doesn't exist in the integer list." << endl;
		return 0;
	}
	return currentIndex;
}

/**
 *	The delete() function remove the value of the specific index position 
 *	in the sorted list
 *	
 *	@param int index containing the index number that be removed from the 
 *	sorted list
 */
void SortedIntegerList::indexDelete(int index) {
	Node *currPtr = headPtr;
	Node *prevPtr = nullptr;
	int currentIndex = 0;

	while (index != currentIndex) {
		currentIndex++;
		prevPtr = currPtr;
		currPtr = currPtr->nextPtr;
	}
	prevPtr->nextPtr = currPtr->nextPtr;
	delete currPtr;
}

int main() {
	SortedIntegerList list;

	list.insert(78);
	cout << list.getElement(0) << endl;
	list.insert(77);
	list.insert(44);
	list.insert(5);
	// for (int i = 0; i < list.getLength(); i++) {
	// 	cout << list.getElement(i) << endl;
	// }
	return 0; 

}