#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <class T>
class node{
private: 
	T data;
	node * left;
	node * right;
public: 
	node();
	node(T data);
	node(T data, node* l, node * r);
	T getData();
	node * getLeft();
	node * getRight();
	void setData(T data);
	void setLeft(node * left);
	void setRight(node * right);
};
