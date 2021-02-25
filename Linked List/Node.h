#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
public:
	Node() {
		val = 0;
		next = nullptr;
	}
	Node(const T &val) {
		this->val = val;
	}
	Node(const Node<T>& rhs) {
		*this = rhs;
	}
	Node<T>& operator=(const Node<T> &rhs) {
		val = rhs.val;
		next = rhs.next;
		return *this;
	}

	T val;
	Node<T>* next;
};




#endif // !NODE_H

