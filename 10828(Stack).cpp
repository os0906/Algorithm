#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
class node {
public:
	node();
private:
	int elem;
	node* prev;
	friend class Stack;
};

class Stack {
private:
	node* t;
	int s;
public:
	Stack();
	void push(int n);
	int pop();
	bool empty();
	int size();
	int top();
};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, tmp;
	int n1{ 0 }, n2{ 0 };
	string str;
	cin >> N;
	Stack s;
	int* arr = new int[N];
	cin >> str;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}
	for (int i{ 0 }; i < str.length(); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			s.push(arr[str[i] - 17]);
		}
		else {
			if (str[i] == '*') {
				n2 = s.pop();
				n1 = s.pop();
				s.push(n1 * n2);
			}
			else if (str[i] == '+') {
				n2 = s.pop();
				n1 = s.pop();
				s.push(n1 + n2);
			}
			else if (str[i] == '-') {
				n2 = s.pop();
				n1 = s.pop();
				s.push(n1 - n2);
			}
			else if (str[i] == '/') {
				n2 = s.pop();
				n1 = s.pop();
				s.push(n1 / n2);
			}
		}
	}
}

Stack::Stack()
{
	t = nullptr;
	s = 0;
}

void Stack::push(int n)
{
	node* pushNode = new node;
	if (size == 0) {
		t = pushNode;

	}
	else {
		pushNode->prev = t;
		t = pushNode;
	}
	pushNode->elem = n;
	s++;
}

int Stack::pop()
{
	int tp{ 0 };
	if (size == 0) {
		cout << -1 << endl;
	}
	else {
		cout << top() << endl;
		tp = top();
		node* tmp = t;
		t = t->prev;
		delete tmp;
		s--;
	}
	return tp;
}

bool Stack::empty()
{
	return !size;
}

int Stack::size()
{
	return s;
}

int Stack::top()
{
	if (size == 0) {
		return -1;
	}
	else {
		return t->elem;
	}
}

node::node()
{
	elem = 0;
	prev = nullptr;
}
