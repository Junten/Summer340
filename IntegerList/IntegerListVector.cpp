// The implementation file of the header file "IntegerListVector.h".

#include <stdexcept>
#include <vector>
#include "IntegerListVector.h"
using namespace std;

/** 
 * 	The default constructor, initializes length to be 0 and the list is 	
 *	pointing a empty vector.
 */
IntegerListVector::IntegerListVector():length(0) {
	list = new vector<int> ();
}

/** 
 * 	The push() function adds an integer to the beginning of the integer list.
 *
 *  @param int value contains the integer that be added to the integerlist.
 */
void IntegerListVector::push(int value) {
	list->insert(list->begin(), value);
	length++;
}

/**
 * 	The pop() function removes and retrieves the integer from the beginning 
 *	of the integer list
 *
 * 	@returns int popValue contains the integer that is removed from the 
 *	integer list
 */
int IntegerListVector::pop() {
	if (length == 0) {
		throw logic_error("Error in pop() function! The list is empty!");
	}

	length--;
	int popValue = list->front();
	list->erase(list->begin());
	return popValue;
}

/**	
 *  The pushEnd() function adds an integer at the end of the integer list
 *
 *	@param int value contains the integer that is added to the integer list
 */
void IntegerListVector::pushEnd(int value) {
	list->push_back(value);
	length++;
}

/**	
 *	The popEnd() retrieves and removes the intgegen from the end of the list
 *
 *	@returns int contains the integer that is removed from the list
 */
int IntegerListVector::popEnd() {
	if (length == 0) {
		throw logic_error("Error in popEnd() function! The list is empty!");
	}
	
	length--;
	int popValue = list->back();
	list->pop_back();
	return popValue;
}
/**	
 *	The getLength() gets the numbers of integers in the integer list
 *
 *	@returns int contains the numbers of integer in the integer list
 */
int IntegerListVector::getLength() {
	return length;
}

/**	
 *	The getElement() retrieves the integer based on the vlaue's position in 
 *	the integer list
 *
 *	@param int element contains the integer referring to the index 
 *	number
 *
 *	@returns int contains the value of the list in the specific position
 */
int IntegerListVector::getElement(int element) {
	if (element < 0 || element >= length) {
		throw out_of_range("Out of Range Error in getElement()");
	}

	return list->at(element);
}

/**
 *	The bubbleSort() function arranges the value of list in the ascending 
 *	order 
 */
void IntegerListVector::bubbleSort() {
 	bool sorted = false;	
	int beginIndex = 0;
	int endIndex = length;

	for (int i = 1; i < endIndex && !sorted; i++) {
		sorted = true;
		
		for (int j = beginIndex; j < endIndex - i; j++) {
			if (list->at(j) > list->at(j + 1)) {
				int temp = list->at(j);
		    	list->at(j) = list->at(j + 1);
				list->at(j + 1) = temp;
				sorted = false;
			}
		}	
	}
}
