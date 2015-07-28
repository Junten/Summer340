// The implementation file of the header file "List.h".

#include <stdexcept>
using namespace std;

/** 
 * 	The default constructor, initializes int length to be 0 and head point to 
 *	be null pointer
 */
template<typename DataType>
List<DataType>::List():length(0),headPtr(nullptr) {
}

/** 
 * 	The push() function adds a value to the beginning of the list.
 *
 *  @param DataType value contains the value that be added to the lsit.
 */
template<typename DataType>
void List<DataType>::push(DataType value) {
	length++;
	Node<DataType> *newPtr = new Node<DataType>();
	newPtr->data = value;
	newPtr->nextPtr = headPtr;
	headPtr = newPtr;
}

/**
 * 	The pop() function removes and retrieves the value from the beginning of 
 *  the list
 *
 * 	@returns DataType contains the value that is removed from the list
 */
template<typename DataType>
DataType List<DataType>::pop(){
	if (length == 0) {
		throw logic_error("Error in pop() function! The list is empty!");
	}
	
	length--;
	DataType popValue = 0;
	Node<DataType> *tempPtr = headPtr;
	popValue = headPtr->data;
	headPtr = tempPtr->nextPtr;
	delete tempPtr;
	return popValue;
}

/**	
 *  The pushEnd() function adds a value at the end of the list
 *
 *	@param DataType contains the value that is added to the list
 */
template<typename DataType>
void List<DataType>::pushEnd(DataType value) {
	length++;
	Node<DataType> *newPtr = new Node<DataType>();
	newPtr->data = value;
	newPtr->nextPtr = nullptr;
	Node<DataType> *currPtr = headPtr;

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
 *	The popEnd() retrieves and removes the value from the end of the list
 *
 *	@returns DataType contains the value that is removed from the list
 */
template<typename DataType>
DataType List<DataType>::popEnd() {
	if (length == 0) {
		throw logic_error("Error in popEnd() function! The list is empty!");
	}

	length--;
	DataType popValue = 0;
	Node<DataType> *currPtr = headPtr;
	Node<DataType> *prePtr = nullptr;
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
 *	The getLength() gets the numbers of value in the list
 *
 *	@returns int containing the numbers of integer in the list
 */
template<typename DataType>
int List<DataType>::getLength(){
	return length;
}

/**	
 *	The getElement() get the integer based on the element position in the list
 *
 *	@param int element contains the index number refers to the value in the 
 *	list
 *
 *	@returns DataType contains the value of the list in the specific position
 */
template<typename DataType>
DataType List<DataType>::getElement(int element) {
	if (element < 0 || element >= length) {
		throw out_of_range("Out of Range Error in getElement()");
	}

	Node<DataType> *currPtr = headPtr;
	for(int i = 0; i < element; i++) {
		currPtr = currPtr->nextPtr;
	}
	return currPtr->data;
}

/**
 *	The bubbleSort() arranges the value of the list in ascending order
 */
template<typename DataType>
void List<DataType>::bubbleSort() {
	Node<DataType> *stopPtr = nullptr; 
	Node<DataType> *endPtr = nullptr; 
	Node<DataType> *tempPtr = nullptr;
	Node<DataType> *currPtr = new Node<DataType>();

	//	adding one more Node in the beginning of the list
	currPtr->nextPtr = headPtr;
	//	headPte pointing to the added Node, delete the added Node after sorting
	headPtr = currPtr;


	///	record the last swapped postion, and stop the loop when last the 
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