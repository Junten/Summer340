#include <iostream>
#include "IntegerListArray.h"
using namespace std;

int main() {
	IntegerListArray list;
	list.pushEnd(43);
	list.push(33);
	list.push(34);
	list.push(2);
	list.push(3898);
	list.push(4324);

	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	cout << endl;
	list.bubbleSort();
	for (int i = 0; i < 6; i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	cout << "popEnd(): " << list.popEnd() << endl;
	cout << "pop(): " << list.pop() << endl;
	return 0;
}