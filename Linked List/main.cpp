#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;
int main() {
	LinkedList<int> list;
	LinkedList<int> list2;
	LinkedList<int> empty;


	for (int i = 0; i < 20; i++) {
		list.insertBack(i);
	}
	list.print();

	cout << list.back()->val << " " << list.front()->val << endl;

	cout << list.get(4)->val << endl;
	list.insertBack(4);
	list.remove(4);
	list.print();

	for (int i = 0; i < 20; i++) {
		list2.insertFront(i);
	}
	list2.print();
	
	return 0;
}