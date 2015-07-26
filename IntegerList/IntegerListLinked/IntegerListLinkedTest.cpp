/*  IntegerList.cpp
 *  6/25/15 by MHS
 */

#include "IntegerListLinked.h"
#include <iostream>
using namespace std;

/**
 * This main method tests the IntegerList method.  An IntegerList
 * is populated and the values printed out to the console.
 */
int main() {
	IntegerListLinked list;
	// list.pop();
	list.pushEnd(1);
	list.push(93);
	list.pushEnd(33);
	list.pushEnd(43);
	list.push(34);
	list.push(2);
	list.push(3898);
	list.push(4324);

	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	cout << endl;
	//list.getElement(56);
	list.bubbleSort();
	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	cout << "pop(): " << list.pop() << endl;
	cout << "popEnd(): " << list.popEnd() << endl;
	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	return 0;
}


