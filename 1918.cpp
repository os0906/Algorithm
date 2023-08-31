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
	char elem;
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
	char pop();
	bool empty();
	int size();
	char top();
};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	Stack s;
	cin >> str;
	for (int i{ 0 }; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == ')') {
			while (s.top() != '(') {
				cout << s.pop();
			}
			s.pop();
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (s.top() != '('&&!s.empty()) {
				cout << s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (s.top() == '*' || s.top() == '/') {
				cout << s.pop();
			}
			s.push(str[i]);
		}
		else {
			cout << str[i];
		}
	}
	while (s.size()) {
		cout << s.top();
		s.pop();
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
	if (s == 0) {
		t = pushNode;

	}
	else {
		pushNode->prev = t;
		t = pushNode;
	}
	pushNode->elem = n;
	s++;
}

char Stack::pop()
{
	int tp{ 0 };


	tp = top();
	node* tmp = t;
	t = t->prev;
	delete tmp;
	s--;
	return tp;

}

bool Stack::empty()
{
	return !s;
}

int Stack::size()
{
	return s;
}

char Stack::top()
{
	if (s == 0) {
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
