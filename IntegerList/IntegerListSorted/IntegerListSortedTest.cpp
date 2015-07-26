#include <iostream>
#include "IntegerListSorted.h"
using namespace std;


int main() {
	IntegerListSorted list;
	//list.remove(1);
	list.insert(43);
	list.insert(34);
	list.insert(2);
	list.insert(3898);
	list.insert(4324);
	cout << "Size of list: " << list.getLength() << endl;
	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	list.remove(0);
	cout << "After remove(0), Size of list: " << list.getLength() << endl;
	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	return 0;
}
