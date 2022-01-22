#include "stack.h"
#include "iostream"

stack::stack():top(NULL), size_of_stack(0) {

}

stack::~stack()
{
	while (top->next != NULL) {
		pop();
	}
}

void stack::push(int element)
{
	if (!size_of_stack) {
		top = new Node;
		top->data = element;
		top->next = NULL;
	}
	else {
		Node* new_node = new Node;
		new_node->data = top->data;
		new_node->next = top->next;
		
		top->data = element;
		top->next = new_node;
	}
	++size_of_stack;
}

void stack::pop() {
	if(empty()) {
		std::cout << "Nothing to remove\n";
		return;
	}
	Node* new_top = new Node;
	new_top = top->next;
	delete top->next;

	top->data = new_top->data;
	top->next = new_top->next;
	delete new_top;

	--size_of_stack;
}

int stack::peek() {
	return top->data;
}

bool stack::empty() {
	if(size_of_stack == 0) return true;
	return false;
}

int stack::size() {
	return size_of_stack;
}

void stack::print() {
	Node* current = new Node;
	current = top;
	while(current != NULL){
		std::cout << current->data << " ";
		current = current->next;
	}
	delete current;
}