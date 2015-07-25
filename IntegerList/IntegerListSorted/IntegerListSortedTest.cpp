#include <iostream>
#include "IntegerListSorted.h"
using namespace std;


int main() {
	IntegerListSorted list;
	list.insert(43);
	list.insert(34);
	list.insert(2);
	list.insert(3898);
	list.insert(4324);

	for (int i = 0; i < list.getLength(); i++) {
		cout << "[" << i << "]: " << list.getElement(i) << endl;
	}
	return 0;
}
