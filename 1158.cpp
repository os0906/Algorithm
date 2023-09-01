#include <iostream>
<<<<<<< HEAD
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	queue <int> q;
	for (int i{ 0 }; i < N; i++) {
		q.push(i + 1);
	}
	cout << "<";
	while (!q.empty()) {
		for (int i{ 0 }; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout<< q.front();
		q.pop();
		if (!q.empty()) {
			cout<< ", ";
		}
	}
	cout << ">";
=======
using namespace std;

class node {
private:
	int elem;
	node* next;
public:
	node() :elem{ 0 }, next{ nullptr } {};
	friend class Queue;
};

class Queue {
private:
	node* head;
	node* tail;
	int s;
public:
	Queue() :head{ nullptr }, tail{ nullptr }, s{ 0 } {};
	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return head->elem;
		}


	}
	int rear() {
		if (empty()) {
			return -1;
		}
		else {
			return tail->elem;
		}
	}
	int size() {
		return s;
	}
	void enqueue(int n) {
		node* enqueueNode = new node;
		enqueueNode->elem = n;
		if (empty()) {
			head = tail = enqueueNode;
		}
		else {
			tail->next = enqueueNode;
			tail = enqueueNode;
		}
		s++;
	}
	int dequeue() {
		if (empty()) {
			return -1;
		}
		else {
			node* dequeueNode = head;
			int tmp{ dequeueNode->elem };
			head = head->next;
			delete dequeueNode;
			s--;
			return tmp;
		}
	}
	bool empty() {
		return !s;
	}
};



int main() {
	int N;
	int K;
	cin >> N >> K;
	Queue q;
	for (int i = 1; i <= N; i++) {
		q.enqueue(i);
	}
	cout << '<';
	while (!q.empty()) {
		for (int i = 0; i < K-1; i++) {
			q.enqueue(q.dequeue());
		}
		cout << q.front();
		
		q.dequeue();
		if (!q.empty()) cout << ", ";
	}
	cout << '>';
>>>>>>> ff3643f445500a4356dba7142f1b392199b4ac8b
}