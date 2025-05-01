#include "pch.h"
#include "Tree.h"

template <class T>
Tree<T>::Tree() {
	this->root = nullptr; 
}

template <class T>
void Tree<T>::setRoot(node<T> * root) {
	this->root = root;
}

template <class T>
node<T> * Tree<T>::getRoot() {
	return this->root; 
}

template <class T>
void Tree<T>::insert(T data) {
	if (this->root == nullptr) {
		node<T> * rootempt = new node<T>(data);
		this->root = rootempt;
		this->root->setLeft(nullptr); 
		this->root->setRight(nullptr);
	}
	else if (this->root != nullptr) {
		if (data < this->root->getData()) {
			this->root->setLeft(insert(this->root->getLeft(), data)); 
		}
		else {
			this->root->setRight(insert(this->root->getRight(), data));
		}
	}
}

template <class T>
node<T> * Tree<T>::insert(node<T> * n , T data) {
	if (n == nullptr) {
		node<T> * rootempt = new node<T>(data);
		n = rootempt;
		n->setLeft(nullptr);
		n->setRight(nullptr);
	}
	else {
		if (data < n->getData()) {
			n->setLeft(insert(n->getLeft(), data));
		}
		else {
			n->setRight(insert(n->getRight(), data));
		}
	}
	return n;
}

template <class T>
void Tree<T>::preOrderTraversal(node<T> * n) {
	if (n == nullptr) {
		return;
	}

	cout << n->getData() << "->";

		if ( n->getLeft() != nullptr)
		preOrderTraversal(n->getLeft());
		if ( n->getRight() != nullptr)
		preOrderTraversal(n->getRight());
}


template <class T>
void Tree<T>::postOrderTraversal(node<T> * n) {
	if (n == nullptr) {
		return;
	}
	if (n->getLeft() != nullptr) {
		postOrderTraversal(n->getLeft());
	}
	if (n->getRight() != nullptr) {
		postOrderTraversal(n->getRight());
	}

	cout << n->getData() << "->";		
}


template <class T>
void Tree<T>::inOrderTraversal(node<T> * n) {
	if (n == nullptr) {
		return;
	}
	if (n->getLeft() != nullptr) {
		inOrderTraversal(n->getLeft());
	}

	cout << n->getData() << "->";

	if (n->getRight() != nullptr) {
		inOrderTraversal(n->getRight());
	}	
}

template <class T>
bool Tree<T>::find(node<T> * n , T data) {
	bool found = false; 
	if (n->getData() == data) {
		return true;
	}
	else {
		if (n->getLeft() != nullptr && !found)
			found = find(n->getLeft(), data);
		if (n->getRight() != nullptr && !found)
			found = find(n->getRight(), data);
	}
	return found;
}

template <class T>
void Tree<T>::BFPrint(node<T> * n) {
	if (n == nullptr) {
		return;
	}
	queue<node <T>> q;
	q.push(*n);
	while (!q.empty()) {
		node<T> temp = q.front();
		if (temp.getLeft() !=nullptr)
			q.push(*temp.getLeft());
		if (temp.getRight() != nullptr)
			q.push(*temp.getRight()); 
		cout << temp.getData() << "->"; 
		q.pop(); 
	}
}

template <class T>
bool Tree<T>::BFSearch(node<T> * n, T data) {
	bool found = false; 
	if (n != nullptr) {
		queue< node<T> > q; 
		q.push(*n);
		while (!q.empty()) {
			node<T> temp = q.front(); 
			cout << temp.getData();
			if (temp.getData() == data) {
				found= true;
				break;
			}
			else {
				cout << "->";
				if (temp.getLeft() != nullptr && !found)
					q.push(*temp.getLeft());
				if (temp.getRight() != nullptr && !found)
					q.push(*temp.getRight());
			}
			q.pop(); 
		}
	}
	if (found)
		cout << " Found! =";
	else
		cout << " Notfound =";
	return found; 
}