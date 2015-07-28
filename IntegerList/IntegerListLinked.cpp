//	The implementation file of the header file "IntegerListLinked.h".

#include <stdexcept>
#include "IntegerListLinked.h"
using namespace std;

/** 
 * 	The default constructor, initializes int length to be 0 and the linked   
 *	list first node headPtr to be null pointer. 
 */
IntegerListLinked::IntegerListLinked():length(0),headPtr(nullptr) {
}

/**
 *	The default destructor, delete all the nodes of the integer list
 */
IntegerListLinked::~IntegerListLinked() {
	Node<int> *tempPtr = headPtr;
	while (headPtr) {
		headPtr = headPtr->nextPtr;
		delete tempPtr;
		tempPtr = headPtr;
	}
}

/** 
 * 	The push() function add an integer to the beginning of the list.
 *
 *  @param int value contains the integer that be added to the lsit.
 */
void IntegerListLinked::push(int value) {
	length++;
	Node<int> *newPtr = new Node<int>();
	newPtr->data = value;
	newPtr->nextPtr = headPtr;
	headPtr = newPtr;
}

/**
 * 	The pop() function removes and retrieved the integer from the beginning of 
 *	the list
 *
 * 	@returns int contains the integer that is removed from the 
 *	list
 */
int IntegerListLinked::pop(){
	if (!headPtr) {
		throw logic_error("Error in pop() function! The list is empty!");
	}
	
	length--;
	int popValue = 0;
	Node<int> *tempPtr = headPtr;
	popValue = headPtr->data;
	headPtr = tempPtr->nextPtr;
	delete tempPtr;
	return popValue;
}

/**	
 *  The pushEnd() function add an integer at the end of the list
 *
 *	@param int value contains the integer that is adding to the list
 */
void IntegerListLinked::pushEnd(int value) {
	length++;
	Node<int> *newPtr = new Node<int>();
	newPtr->data = value;
	newPtr->nextPtr = nullptr;
	Node<int> *currPtr = headPtr;
	
	if (!headPtr) {
		headPtr = newPtr;
	} else {
		while (currPtr->nextPtr) {
			currPtr = currPtr->nextPtr;
		}
		currPtr->nextPtr = newPtr; 
	}
}

/**	
 *	The popEnd() retrieve and remove the intgegen from the end of the list
 *
 *	@returns int contaibs the integer that is removed from the list
 */
int IntegerListLinked::popEnd() {
	if (headPtr == nullptr) {
		throw logic_error("Error in popEnd() function! The list is empty!");
	}

	length--;
	int popValue = 0;
	Node<int> *currPtr = headPtr;
	Node<int> *prePtr = nullptr;
	while (currPtr->nextPtr) {
		prePtr = currPtr;
		currPtr = currPtr->nextPtr;
	}
	
	if (currPtr == headPtr) {
		headPtr = nullptr;
	} else {
		prePtr->nextPtr = nullptr;
	}

	popValue = currPtr->data;
	delete currPtr;      
	
	return popValue;
}

/**	
 *	The getLength() get the numbers of integers in the list
 *
 *	@returns int containing the numbers of integer in the list
 */
int IntegerListLinked::getLength() {
	return length;
}

/**	
 *	The getElement() get the integer based on the element position in the list
 *
 *	@param int element contains the index number to the value in the list
 *
 *	@returns int contains the value of the list in the specific position
 */
int IntegerListLinked::getElement(int element){
	if (element < 0 || element >= length) {
		throw out_of_range("Out of Range Error in getElement()");
	}

	Node<int> *currPtr = headPtr;
	for(int i = 0; i < element; i++) {
		currPtr = currPtr->nextPtr;
	}
	return currPtr->data;
}

/**
 *	The bubbleSort() arranges the value of the  list in ascending order
 */
void IntegerListLinked::bubbleSort() {
	Node<int> *stopPtr = nullptr; 
	Node<int> *endPtr = nullptr; 
	Node<int> *tempPtr = nullptr;
	Node<int> *currPtr = new Node<int>();

	//	adding one more Node in the beginning of the list for comparistion 
	currPtr->nextPtr = headPtr;
	//	headPte pointing to the added Node, delete the added Node after sorting
	headPtr = currPtr;


	//	record the last swapped postion, and stop the loop when last the 
	//	swapped postion at the first Node
	for (stopPtr = nullptr; stopPtr != headPtr; stopPtr = endPtr) {
		for (endPtr = currPtr = headPtr; currPtr->nextPtr->nextPtr != stopPtr; 
			currPtr = currPtr->nextPtr) {

			if (currPtr->nextPtr->data > currPtr->nextPtr->nextPtr->data) {
				//	store the current postion before swaping
				tempPtr = currPtr->nextPtr->nextPtr;
				//	swapped the pointersss
				currPtr->nextPtr->nextPtr = tempPtr->nextPtr;
				tempPtr->nextPtr = currPtr->nextPtr;
				currPtr->nextPtr = tempPtr;
				//	store the swapped postion
				endPtr = currPtr->nextPtr->nextPtr;
			}
		}
	}

	//	delete the first Node which is created before for comparison
	currPtr = headPtr;
	headPtr = headPtr->nextPtr;
	delete currPtr;
}