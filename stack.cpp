#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include <algorithm>  
#include <stdio.h>

using std::vector;
using std::cout;
using std::cin;
using std::string;




template<class T> class Stack {
	T value;
	Stack* next;
	Stack* top;

public:
	Stack() {
		top = NULL;
	}


	void add_top(T value) {
		if (top == NULL) {
			top = (Stack*)malloc(sizeof(Stack));
			(top)->value = value;
			(top)->next = NULL;
		}
		else {
			Stack* a;
			a = (Stack*)malloc(sizeof(Stack));
			a->value = value;
			a->next = top;
			top = a;
		}
		
	}

	void pop_top() {
		Stack* a = top;
		top = a->next;
		free(a);
	}


	T top_pick() {
		return top->value;
	}


	void print() {
		Stack* a = top;
		while (a != NULL) {
			cout << a->value << " ";
			a = a->next;
		}
	}
};




int main() {
	vector<int>check1 = { 1, 2, 3, 4, 5 };
	Stack<int> stack1;
	for (int i = 0; i < check1.size(); i++) {
		stack1.add_top(check1[i]);
	}
	stack1.print();
	cout << std::endl;
	cout << stack1.top_pick();
	stack1.pop_top();
	cout << std::endl;
	stack1.print();


	cout << std::endl;
	cout << std::endl;


	vector<double>check2 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	Stack<double> stack2;
	for (int i = 0; i < check2.size(); i++) {
		stack2.add_top(check2[i]);
	}
	stack2.print();
	cout << std::endl;
	cout << stack2.top_pick();
	stack2.pop_top();
	cout << std::endl;
	stack2.print();


	cout << std::endl;
	cout << std::endl;


	vector<char>check3 = { 'a', 'b', 'c', 'd', 'e' };
	Stack<char> stack3;
	for (int i = 0; i < check3.size(); i++) {
		stack3.add_top(check3[i]);
	}
	stack3.print();
	cout << std::endl;
	cout << stack3.top_pick();
	stack3.pop_top();
	cout << std::endl;
	stack3.print();


	cout << std::endl;
	cout << std::endl;

	/*
	vector<string>check4 = { "one", "two", "three", "four", "five" };
	Stack<string> stack4;
	for (int i = 0; i < check4.size(); i++) {
		stack4.add_top(check4[i]);
	}
	stack4.print();
	cout << std::endl;
	cout << stack4.top_pick();
	stack4.pop_top();
	cout << std::endl;
	stack4.print();
	*/


}
