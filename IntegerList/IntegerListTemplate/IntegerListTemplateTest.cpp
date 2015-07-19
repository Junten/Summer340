#include <iostream>
#include "IntegerListTemplate.h"
using namespace std;

int main() {
	IntegerListTemplate<int> list;
	list.push(43);
	list.push(34);
	list.push(2);
	list.push(3898);
	list.push(4324);

	for (int i = 0; i < 5; i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	cout << endl;
	list.bubbleSort();
	for (int i = 0; i < 5; i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}

	return 0;
}