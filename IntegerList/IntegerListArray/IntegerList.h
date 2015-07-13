/**
 * \mainpage
 *		<h1>In Class Exercise 2</h1>
 *		<h3>
 *			File Name: IntegerList.h <br>
 *			CSC 340 Summer 2015 <br>
 *			Team Members: Juteng Tan, Tony Tran, David Tran
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
 *			<cite>Source of UML: Provided by instructor, Marc Sosnick-Perez.</cite>
 * 		</p>
 */

#ifndef __INTEGERLIST__H__
#define __INTEGERLIST__H__

class IntegerList{
private:
	// Dynamic array pointer 
	int *list;   
	// The size of the integer list
	int length;  
public:
	IntegerList();
	~IntegerList();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
	void bubbleSort();
};
#endif
