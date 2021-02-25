#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <iostream>

template <class T>
class LinkedList {
public:
	LinkedList(); // constructor
	LinkedList(const LinkedList<T>& rhs); // copy constructor

	LinkedList<T>& operator=(const LinkedList<T>& rhs); // = overload

	~LinkedList(); // destructor

	Node<T>* front(); 	
	Node<T>* back(); 
	Node<T>* get(const T& val); 
	Node<T>* get(Node<T>* node); 

	void insertBack(const T& val); 
	void insertFront(const T& val);
	
	void remove(const T& val);
	void removeAll();
	bool isEmpty();

	int numberOfNodes();

	void print();

private:
	Node<T>* head;
};

template <class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
	*this = rhs;

}

template <class T>
LinkedList<T>::~LinkedList() {
	removeAll();
}


template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	if (this != &rhs) {
		removeAll();
		if (!rhs.head) {
			head = nullptr;
		}
		else {
			Node<T>* ptr = rhs.head;
			while (ptr) {
				insertBack(ptr->val);
				ptr = ptr->next;
			}
		}
	}
	return *this;
}

template <class T>
Node<T>* LinkedList<T>::front() {
	return head;
}

template <class T>
Node<T>* LinkedList<T>::back() {
	if (isEmpty()) return nullptr;

	Node<T>* ptr = head;
	while (ptr->next) { // go to the last node
		ptr = ptr->next;
	}

	return ptr;
}

template <class T>
Node<T>* LinkedList<T>::get(const T& val) {
	if (isEmpty()) return nullptr;

	Node<T>* ptr = head;
	while (ptr) { // traverse
		if (ptr->val == val) {
			return ptr;
		}
		ptr = ptr->next;
	}

	return nullptr; // if not founded, return nullptr.
}

template <class T>
Node<T>* LinkedList<T>::get(Node<T>* node) {
	if (isEmpty()) return nullptr;

	Node<T>* ptr = head;
	while (ptr) { // traverse
		if (ptr->val == node->val && ptr->next == node->next) { // if they are the same node
			return ptr;
		}
		ptr = ptr->next;
	}

	return nullptr; // if not founded, return nullptr.
}

template <class T>
void LinkedList<T>::insertBack(const T& val) {
	Node<T>* add = new Node<T>(val);

	if (isEmpty()) {
		head = add;
		return;
	}

	Node<T>* ptr = head;
	while (ptr->next) { // go to the last node
		ptr = ptr->next;
	}
	ptr->next = add; // append the new node to the last item
}

template <class T>
void LinkedList<T>::insertFront(const T& val) {

	Node<T>* add = new Node<T>(val);

	if (isEmpty()) {
		head = add;
		return;
	}

	Node<T>* temp = head; // keep head in temp
	head = add; // change head with new node
	add->next = temp; // change new node's next with old head
}

template <class T>
void LinkedList<T>::remove(const T& val) {
	if (isEmpty()) return;

	Node<T>* prev = head;
	Node<T>* curr = head->next;
	while (curr) {
		if (curr->val == val) {
			Node<T>* tmp = curr; // store the deleting value in tmp
			prev->next = curr->next; // prev's next become next's next;
			curr = curr->next; // curr goes the next val
			delete tmp; // delete curr
			continue;
		}
		curr = curr->next;
		prev = prev->next;
	}
}

template <class T>
void LinkedList<T>::removeAll() {
	Node<T>* prev = head;
	Node<T>* curr = head;
	while (curr) {
		curr = curr->next;
		delete prev;
		prev = curr;
	}
	head = nullptr;
}


template <class T>
bool LinkedList<T>::isEmpty() {
	return head == nullptr;
}

template <class T>
int LinkedList<T>::numberOfNodes() {
	if (isEmpty()) return 0;

	int count = 0;
	Node<T>* ptr = head;

	while (ptr) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

template <class T>
void LinkedList<T>::print() {
	if (isEmpty()) {
		std::cout << "empty linked list." << std::endl;
		return;
	}


	Node<T>* ptr = head;
	while (ptr) {
		std::cout << ptr->val << ' ';
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

#endif // !LINKED_LIST_H
