// 6/26/2015
// CSC 340, Summber 2015
// This is the implementation file of the header file "IntegerList.h".
// It contains the construction and functions method of the class IntegerList,
// which is in the header file.

#include <iostream>
#include <vector>
#include "IntegerList.h"
using namespace std;

/** 
 * 	The default constructor, initializes length to be 0 and the pointerlist to
 * 	be null pointer. 
 */
IntegerList::IntegerList():length(0) {
	list = new vector<int> ();
}

/** 
 * 	The push() function add an integer to the beginning of the integer list.
 *
 *  @param int <b>value</b> contains the integer that be added to the integerlist.
 * 
 */
void IntegerList::push(int value) {
	list->insert(list->begin(), value);
	length++;
}

/**
 * 	The pop() function removes and retrieved the integer from the beginning 
 *	of the integer list
 *
 * 	@returns int <b>popValue</b> contains the integer that is removed from 
 *	the integer list
 */
int IntegerList::pop(){
	int popValue = list->front();
	list->erase(list->back());
	length--;
	return popValue;
}

/**	
 *  The pushEnd() function add an integer at the end of the integer list
 *
 *	@param int <b>value</b> contains the integer that is adding to the integer list
 */
void IntegerList::pushEnd(int value) {
	list->push_back(value);
	length++;
}

/**	
 *	The popEnd() retrieve and remove the intgegen from the end of the array
 *
 *	@returns int contaibs the integer that is removed from the array
 */
int IntegerList::popEnd() {
	int popValue = list->back();
	length--;
	list->pop_back();
	return popValue;
}
/**	
 *	The getLength() get the numbers of integers in the integer list
 *
 *	@returns int containing the numbers of integer in the integer list
 */
int IntegerList::getLength(){
	return length;
}

/**	
 *	The getElement() get the integer based on the element position in the integer list
 *
 *	@param int <b>element</b> contains the integer referring to the index number
 *
 *	@returns int containing the integer of the list in the specific element position
 */
int IntegerList::getElement(int element){
	return list->at(element);
}

/**
 *	The bubbleSort() function sort the list from small to large 
 *
 *	@param int end is the last position of the element that would be sorted
 */
void IntegerList::bubbleSort(int end) {
 	bool sorted = false;	
	int beginIndex = 0;
	int endIndex = end;

	for (int i = 1; i < endIndex && !sorted; i++) {
		sorted = true;
		
		for (int j = beginIndex; j < endIndex - i; j++) {
			if (list->at(j) > list->at(j + 1)) {
				int temp = list->at(j);
		    	list->at(j) = list->at(j + 1);
				list->(j + 1) = temp;
				sorted = false;
			}
		}	
	}
}

int main() {
	IntegerList array = IntegerList();

}
