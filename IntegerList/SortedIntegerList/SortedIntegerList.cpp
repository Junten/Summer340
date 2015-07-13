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
	headPtr = 0;
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
	Node *prevPtr = 0;
	Node *newPtr = new Node();
	newPtr->data = value;
	newPtr->nextPtr = 0;

	while (value > currPtr->data) {
		prevPtr = currPtr;
		currPtr = currPtr->nextPtr;
	}

	prevPtr->nextPtr = newPtr;
	newPtr = currPtr;
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
	try {

	} catch() {

	}
	Node *currPtr = headPtr;
	for (int i = 0; i < index; i++) {
		currPtr = currPtr->nextPtr;
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

}

/**
 *	The delete() function remove the value of the specific index position 
 *	in the sorted list
 *	
 *	@param int index containing the index number that be removed from the 
 *	sorted list
 */
void delete(int index) {

}