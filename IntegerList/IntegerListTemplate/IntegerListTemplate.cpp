// 6/26/2015
// CSC 340, Summber 2015

// This is the implementation file of the header file "IntegerList.h".
// It contains the constructor and functions method of the class IntegerList,
// which is in the header file.

#include <iostream>
using namespace std;

/** 
 * 	The default constructor, initializes int <b>length</b> to be 0 and the
 *  linked list first node <b>first</b> to be null pointer. 
 */
template<typename DataType>
IntegerList::IntegerList():length(0) {
	headPtr = new Node();
	headPtr = nullptr;
}

/** 
 * 	The push() function add an integer to the beginning of the list.
 *
 *  @param int <b>value</b> contains the integer that be added to the lsit.
 */
template<typename DataType>
void IntegerList::push(DataType value) {
	length++;
	Node *newPtr = new Node();
	newPtr->data = value;
	newPtr->nextPtr = headPtr;
	headPtr = newPtr;
}

/**
 * 	The pop() function removes and retrieved the integer from the beginning of 
 *  the list
 *
 * 	@returns int <b>popValue</b> contains the integer that is removed from the 
 *	list
 */
template<typename DataType>
DataType IntegerList::pop(){
	if (length == 0) {
		cout << "Error! The list is empty!" << endl;
		return 0;
	}
	
	length--;
	DataType popValue = 0;
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
template<typename DataType>
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
template<typename DataType>
DataType IntegerList::popEnd() {
	if (length == 0) {
		cout << "Error! The list is empty!" << endl;
		return 0;
	}

	length--;
	DataType popValue = 0;
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
template<typename DataType>
int IntegerList::getLength(){
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
template<typename DataType>
DataType IntegerList::getElement(int element){
	Node *currPtr = headPtr;
	for(int i = 0; i < element; i++) {
		currPtr = currPtr->nextPtr;
	}
	return currPtr->data;
}

/**
 *	The bubbleSort() arrange the integer list in ascending order
 */
template<typename DataType>
void IntegerList::bubbleSort() {
	Node *stopPtr = nullptr; 
	Node *endPtr = nullptr; 
	Node *tempPtr = nullptr;
	Node *currPtr = new Node();

	//	adding one more Node in the beginning of the list
	currPtr->nextPtr = headPtr;
	//	headPte pointing to the added Node, delete the added Node after sorting
	headPtr = currPtr;


	//	record the last swapped postion, and stop the loop when last the swapped
	//	postion at the first Node
	for (stopPtr = nullptr; stopPtr != headPtr; stopPtr = endPtr) {
		for (endPtr = currPtr = headPtr; currPtr->nextPtr->nextPtr != stopPtr; 
			currPtr = currPtr->nextPtr) {

			if (currPtr->nextPtr->data > currPtr->nextPtr->nextPtr->data) {
				//	record the current postion before swaping
				tempPtr = currPtr->nextPtr->nextPtr;
				//	swapped the pointersss
				currPtr->nextPtr->nextPtr = tempPtr->nextPtr;
				tempPtr->nextPtr = currPtr->nextPtr;
				currPtr->nextPtr = tempPtr;
				//	record the swapped postion
				endPtr = currPtr->nextPtr->nextPtr;
			}
		}
	}

	//	delete the first Node which is created before for comparison
	currPtr = headPtr;
	headPtr = headPtr->nextPtr;
	delete currPtr;
}