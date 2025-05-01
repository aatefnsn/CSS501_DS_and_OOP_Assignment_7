#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "node.h"
#include <queue>
using namespace std;

template <class T>
class Tree {
private: 
	node<T> * root;

public: 
	Tree(); 
	void setRoot(node<T> * root);
	node<T> * getRoot(); 
	void insert(T data);
	node<T> * insert(node<T> * n, T data);
	bool find(node<T> * n, T data);
	void preOrderTraversal(node<T> * n); 
	void postOrderTraversal(node<T> * n);
	void inOrderTraversal(node<T> * n);
	void BFPrint(node<T> * n);
	bool BFSearch(node<T> * n, T data);
};