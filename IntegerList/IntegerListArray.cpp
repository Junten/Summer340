//	The implementation file of the header file "IntegerListArray.h".

#include <stdexcept>
#include "IntegerListArray.h"
using namespace std;

/** 
 * 	The default constructor, initializes int length to be 0 and the 
 *	pointer list to be null pointer. 
 */
IntegerListArray::IntegerListArray() :length(0), list(nullptr){
}

/**
 *	The default destructor, delete all the nodes of the integer list
 */
IntegerListArray::~IntegerListArray() {
	delete[] list;
}

/** 
 * 	The push() function add an integer to the beginning of the array.
 *
 *  @param int value contains the integer that be added to the array.
 */
void IntegerListArray::push(int value) {
	length++;
	int* listCopy = new int[length];
	listCopy[0] = value;
	for (int i = 0; i < length - 1; i++) {
		*(listCopy + i + 1) = *(list + i);
	}
	delete[] list;
	list = listCopy;
}

/**
 * 	The pop() function removes and retrieved the integer from the beginning of
 *	the array
 *
 * 	@returns int contains the integer that is removed from the array 
 */
int IntegerListArray::pop() {
	if (length == 0) {
		throw logic_error("Error in pop() function! The list is empty!");
	}

	length--;
	int popValue = *list;
	if (length != 0) {
		int* listCopy = new int[length];
		for (int i = 0; i < length; i++) {
			*(listCopy + i) = *(list + i + 1);
		}
		delete[] list;
		list = listCopy;
	}
	else {
		delete[] list;
	}

	return popValue;
}

/**	
 *  The pushEnd() function add an integer at the end of the array 
 *
 *	@param int value contains the integer that is adding to the array
 */
void IntegerListArray::pushEnd(int value) {
	length++;
	int* listCopy = new int[length];

	for (int i = 0; i < length - 1; i++) {
		*(listCopy + i) = *(list + i);
	}

	delete[] list;
	listCopy[length - 1] = value;
	list = listCopy;
}

/**	
 *	The popEnd() retrieve and remove the intgegen from the end of the array
 *
 *	@returns int contaibs the integer that is removed from the array
 */
int IntegerListArray::popEnd() {
	if (length == 0) {
		throw logic_error("Error in popEnd() function! The list is empty!");
	}
	
	length--;
	int popValue = list[length];
	if (length != 0) {
		int* listCopy = new int[length];
		for (int i = 0; i < length; i++) {
			*(listCopy + i) = *(list + i);
		}
		delete[] list;
		list = listCopy;
	}
	else {
		delete[] list;
	}

	return popValue;
}
/**	
 *	The getLength() get the numbers of integers in the array
 *
 *	@returns int containing the numbers of integer in the array
 */
int IntegerListArray::getLength(){
	return length;
}

/**	
 *	The getElement() get the integer based on the element position in the array
 *
 *	@param int element contains the index number to the value in the list
 *
 *	@returns int contains the value of the list in the specific position
 */
int IntegerListArray::getElement(int element){
	if (element < 0 || element >= length) {
		throw out_of_range("Out of Range Error in getElement()");
	}
	return list[element];
}

/**
 *	The bubbleSort() arrange the value of list in ascending order 
 */
void IntegerListArray::bubbleSort() {
 	bool sorted = false;	
	int beginIndex = 0;
	int endIndex = length;

	for (int i = 1; i < endIndex && !sorted; i++) {
		sorted = true;
		
		for (int j = beginIndex; j < endIndex - i; j++) {
			if (*(list+j) > *(list + j + 1)) {
				int temp = *(list + j);
		    	*(list + j) = *(list + j + 1);
				*(list + j + 1) = temp;
				sorted = false;
			}
		}	
	}
}