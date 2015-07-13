/**
 *	\mainpage
 *		<h1>In Class Exercise</h1>
 *		<h3>
 *			File Name: SortedIntegerList.h <br>
 *			CSC 340 Summer 2015 <br>
 *		</h3>
 *		
 *		<p>	
 *			Create a container class named SortedIntegerList that is in ascending
 *			order with following functions:
 *			<ol type="1">
 *				<li>Integers can be added to the sorted list in ascending 
 *					order</li>
 *				<li>Retrieve the value at any specific index number using the
 *					getLength method</li>
 *				<li>Retrieve the number of element from the getLength method</li>
 *				<li> To retrieve the position index number of value in the 
 *					 sorted list</li>
 *				<li>To remove the value of the specific index position 
 *					in the sorted list</li>
 *			</ol>
 *		</p>
 */

#ifndef __SortedIntegerList__H__
#define __SortedIntegerList__H__

//	This is the linked list node class
class Node {
public:
	int data;
	Node *nextPtr;
};

//	Sorted integer list container class 
class SortedIntegerList {
private:
	//	First pointer node of the list
	Node *headerPtr;
	//	The size of the integer list
	int length;

public:
	SortedIntegerList();
	~SortedIntegerList();
	void insert(int value);
	int getElement(int index);
	int getLength();
	int valueIndex(int value);
	void delete(int index);
};

#endif