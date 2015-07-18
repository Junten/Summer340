/**
 * \mainpage
 *		<h1>In Class Exercise 2</h1>
 *		<h3>
 *			File Name: IntegerList.h <br>
 *			CSC 340 Summer 2015 <br>
 *			
 *		</h3>
 *
 *		<p>
 *			Create a container class named IntegerList with the following
 *      	characteristics:
 *			<ol type="1">
 * 				<li>Integers can be added to the beginning of the list by using
 *             		the push method.</li>
 * 				<li>Integers can be retrieved and removed from the beginning of
 *              	the list by using the pop method.</li>
 *				<li>Integers can be added to the end of the list by using the
 *              	pushEnd method.</li>
 * 				<li>Integers can be retrieved and removed from the end of the
 *              	list by using the popEnd method.</li>
 *				<li>You can find out the number of elements from the getLength
 *              	method.</li>
 *				<li>You can get the value at any specific element using the
 *              	getElement method.</li>
 *			</ol>
 *			Create this class using a dynamic array as described in class.
 *      	To delete any arrays that are no longer using.
 *
 *			<cite>
 *				Source of UML: Provided by instructor, Marc Sosnick-Perez.
 * 			</cite>
 * 		</p>
 */

#ifndef __INTEGERLIST__H__
#define __INTEGERLIST__H__

/**
 *	This is the linked list node class
 */

template<typename DataType>
class Node {
public:
	DataType data;
	Node *nextPtr;
};

template<typename DataType>
class IntegerList{
private:
	// First pointer node of the list
	Node *headPtr;   
	// The size of the integer list
	int length;  
public:
	IntegerList();
	void push(DataType value);
	DataType pop();
	void pushEnd(DataType value);
	DataType popEnd();
	int getLength();
	DataType getElement(int element);
	void bubbleSort();
};

#include "IntegerListTemplate.cpp"
#endif
