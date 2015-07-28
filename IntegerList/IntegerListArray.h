/**
 * @mainpage
 *		<h1>List Class Report</h1>
 *		<h3>Last Motify Date: 7/28/15</h3>
 *
 *		<p>
 *			This includes five container classes, as showing below:
 *			<ol type="1">
 *				<li>IntegerListArray</li>
 *				<li>IntegerListVector</li>
 *				<li>IntegerListLined</li>
 *				<li>IntegerListSorted</li>
 * 				<li>List</li>
 *			</ol>
 *
 *			IntegerListArray is using the dynmaic array to implement, it can 
 *			store the integer value as the list. The integer value can be 
 *			inserted in the beginning or at the end of the list, and be removed
 *			from the beging or the end of the list. The value in the list can 
 *			be retrieved by giving specifc index number. The list can be 
 *			sorted by the ascending order. 
 *			
 *			IntegerListVector is using the c++ standard template library 
 *			"vecot"to implement. It uses the stardard template library vector 
 *		    to store the integer value as the list ,and can do the same thing 
 *			as the array class.
 *	
 *			IntegerListLined is using linked list to implement. It uses the 
 *			linked list to stored the integer value in the list, and have same 
 *			functionality as the array class.
 *
 *			IntegerListSorted is also linked list to implement, but it 
 *			automatically arrange the integer value in ascending order when 
 *			inserting value to the list. It can retrieved the integer value 
 *			from the list by giving the index number and index number by 
 *			giving the integer value of the list. The list also can give the 
 *			numbers of the integer value of the list. At last, the integer in 
 *			list can be removed by giving the index number.
 *			
 *			List is usieng template linked list to implement. It can store the
 *			value in any data type in the list by using the template. The list
 *		    also have the functionality as the array class.
 * 		</p>
 */

#ifndef __INTEGERLISTARRAY__H__
#define __INTEGERLISTARRAY__H__

class IntegerListArray{
private:
	int *list;
	int length;
public:
	IntegerListArray();
	~IntegerListArray();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
	void bubbleSort();
};

#endif
