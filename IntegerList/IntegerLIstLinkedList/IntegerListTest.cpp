/*  IntegerList.cpp
 *  6/25/15 by MHS
 */

#include "IntegerList.h"
#include <iostream>
using namespace std;

/**
 * This main method tests the IntegerList method.  An IntegerList
 * is populated and the values printed out to the console.
 */
int main() {

	IntegerList list;

	cout << "length: " << list.getLength() << endl;
	for(int i = 0 ; i < 250 ; i++) {
		list.push(i*10);
	}

	for(int i = 0 ; i < list.getLength() ; i++){
	//	cout << "list[" << i << "]: " << list.getElement(i) << endl;
	}
	return 0;
}


