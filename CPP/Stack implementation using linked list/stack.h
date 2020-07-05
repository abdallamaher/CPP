#pragma once
#include "iostream""

struct Node {
	int data;
	Node* next;
};
class stack
{
private:
	Node* top;
	int size_of_stack;
public:
	stack();

	~stack();

	/*
	- O(1)
	- add element to top of stack
	- param(element)
	*/
	void push(int element);

	/*
	- O(1)
	- remove element from top of stack
	- param()
	*/
	void pop();

	int peek();

	bool empty();

	int size();

	void print();
};

