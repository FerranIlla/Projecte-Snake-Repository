#pragma once
#include<iostream>

class Snake {
	struct Node {
		int i; int j; struct Node* next; 
	};
private:
	int size;
	Node* first;
	Node* last;

public:
	Snake();
	~Snake();
	bool isEmpty() { return size == 0;};
	void Insert(int num);
};

Snake::Snake() {
	first = nullptr;
	last = nullptr;
	size = 0;

}

Snake::~Snake() {
	Node* temp;//create a temporal adress
	while (first != nullptr) {//check the queue is not emptt
		temp = first;
		first = first->next;//move the first
		delete temp;//delete the temporal data
	}
}


void Snake::Insert(int num) {
	//create  a new node of the snake 
	Node* tmp = new Node();

}