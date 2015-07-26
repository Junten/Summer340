#include <iostream>
#include "List.h"
using namespace std;

int main() {
	List<int> list;
	list.pushEnd(89);
	list.push(43);
	list.push(34);
	list.push(2);
	list.pushEnd(3898);
	list.push(4324);

	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	cout << endl;
	list.bubbleSort();
	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}

	return 0;
}