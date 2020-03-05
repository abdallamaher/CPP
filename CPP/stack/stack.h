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

	void push(int element);

	void pop();

	int peek();

	bool empty() const;

	int size() const;

	void print() const;
};

