// 6/26/2015
// CSC 340, Summber 2015
// Team Members: Juteng Tan, Tony Tran, David Tran.
// This is the implementation file of the header file "IntegerList.h".
// It contains the construction and functions method of the class IntegerList,
// which is in the header file.

#include <iostream>
#include <vector>
#include "IntegerListVector.h"
using namespace std;

/** 
 * 	The default constructor, initializes int <b>length</b> to be 0 and the pointer <b>list</b> to 
 * 	be null pointer. 
 */
IntegerListVector::IntegerListVector() :length(0), list(0){
}

/** 
 * 	The push() function add an integer to the beginning of the array.
 *
 *  @param int <b>value</b> contains the integer that be added to the array.
 * 
 */
void IntegerListVector::push(int value) {

}

/**
 * 	The pop() function removes and retrieved the integer from the beginning of the array
 *
 * 	@returns int <b>popValue</b> contains the integer that is removed from the array 
 */
int IntegerListVector::pop(){

}

/**	
 *  The pushEnd() function add an integer at the end of the array 
 *
 *	@param int <b>value</b> contains the integer that is adding to the array
 */
void IntegerListVector::pushEnd(int value) {

}

/**	
 *	The popEnd() retrieve and remove the intgegen from the end of the array
 *
 *	@returns int contaibs the integer that is removed from the array
 */
int IntegerListVector::popEnd() {
	
}
/**	
 *	The getLength() get the numbers of integers in the array
 *
 *	@returns int containing the numbers of integer in the array
 */
int IntegerListVector::getLength(){
	return length;
}

/**	
 *	The getElement() get the integer based on the element position in the array
 *
 *	@param int <b>element</b> contains the integer referring to the index number
 *
 *	@returns int containing the integer of the list in the specific element position
 */
int IntegerListVector::getElement(int element){
	
}

/**
 *	The bubbleSort() function sort the list from small to large 
 *
 *	@param int end is the last position of the element that would be sorted
 */
void IntegerListVector::bubbleSort(int end) {
 	bool sorted = false;	
	int beginIndex = 0;
	int endIndex = end;

//	for (int i = 1; i < endIndex && !sorted; i++) {
//		sorted = true;
//		
//		for (int j = beginIndex; j < endIndex - i; j++) {
//			if ()
//			int temp = *(list + j);
//		    *(list + j) = *(list + j + 1);
//			*(list + j + 1) = temp;
//			sorted = false;
//		}	
//	}
}

int main() {
	IntegerListVector array = IntegerListVector();

}
