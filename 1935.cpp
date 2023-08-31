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
#include <iomanip>
using namespace std;
class node {
public:
	node();
private:
	double elem;
	node* prev;
	friend class Stack;
};

class Stack {
private:
	node* t;
	int size;
public:
	Stack();
	void push(double n);
	double pop();
	bool empty();
	int Size();
	double top();
};



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	double N, tmp;
	double n1{ 0 }, n2{ 0 };
	string str;
	cin >> N;
	Stack n;
	Stack op;
	int arr[26] = { };
	cin >> str;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}
	for (int i{ 0 }; i < str.length(); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			n.push(arr[str[i] - 'A']);
		}
		else if (str[i] == '*' || str[i] == '/' ||str[i] == '+' || str[i] == '-') {
			n2 = n.pop();
			n1 = n.pop();
			if (str[i] == '*') {
				n.push(n1 * n2);
			}
			else if (str[i] == '/') {
				n.push(n1 / n2);
			}
			else if (str[i] == '+') {
				n.push(n1 + n2);
			}
			else if (str[i] == '-') {
				n.push(n1 - n2);
			}
		}
	}
	cout << fixed << setprecision(2) << n.top();
}

Stack::Stack()
{
	t = nullptr;
	size = 0;
}

void Stack::push(double n)
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
	size++;
}

double Stack::pop()
{
	double tp{ 0 };
	if (size == 0) {
		return -1;
	}
	else {
		tp = top();
		node* tmp = t;
		t = t->prev;
		delete tmp;
		size--;
		return tp;
	}

}

bool Stack::empty()
{
	return !size;
}

int Stack::Size()
{
	return size;
}

double Stack::top()
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
