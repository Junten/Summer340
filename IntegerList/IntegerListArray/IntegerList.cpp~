// 6/26/2015
// CSC 340, Summber 2015
// Team Members: Juteng Tan, Tony Tran, David Tran.
// This is the implementation file of the header file "IntegerList.h".
// It contains the construction and functions method of the class IntegerList,
// which is in the header file.

#include <iostream>
#include "IntegerList.h"
using namespace std;

/** 
 * 	The default constructor, initializes int <b>length</b> to be 0 and the pointer <b>list</b> to 
 * 	be null pointer. 
 */
IntegerList::IntegerList() :length(0), list(0){
}

/** 
 * 	The push() function add an integer to the beginning of the array.
 *
 *  @param int <b>value</b> contains the integer that be added to the array.
 * 
 */
void IntegerList::push(int value) {

	length++;
	int* listCopy = new int[length];
	listCopy[0] = value;
	for (int i = 0; i < length - 1; i++){
		listCopy[i + 1] = list[i];
	}

	if (list != 0) {
		delete[] list;
	}
	list = listCopy;
}

/**
 * 	The pop() function removes and retrieved the integer from the beginning of the array
 *
 * 	@returns int <b>popValue</b> contains the integer that is removed from the array 
 */
int IntegerList::pop(){
	if (length == 0) {
		cout << "Error! The list is empty!" << endl;
		return 0;
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
 *	@param int <b>value</b> contains the integer that is adding to the array
 */
void IntegerList::pushEnd(int value) {
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
int IntegerList::popEnd() {
	if (length == 0) {
		cout << "Error! The list is empty!" << endl;
		return 0;
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
int IntegerList::getLength(){
	return length;
}

/**	
 *	The getElement() get the integer based on the element position in the array
 *
 *	@param int <b>element</b> contains the integer referring to the index number
 *
 *	@returns int containing the integer of the list in the specific element position
 */
int IntegerList::getElement(int element){
	return list[element];
}

void IntegerList::bubbleSort() {
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

int main() {
	IntegerList a;
	for(int i = 0; i < 10; i++) {
		a.pushEnd(10 - i);
	}
	a.bubbleSort();
	for (int i = 0; i < a.getLength(); i++) {
		cout << i << ": " << a.getElement(i) << endl;
	}
	return 0;
}
