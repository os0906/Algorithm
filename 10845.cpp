#include <iostream>
using namespace std;

class Queue {
public:
	int arr[10000] = { 0, };
	int size{ 0 };
	int head{ -1 };
	int tail{ -1 };

	int front() {
		if (!size) {
			return -1;
		}
		return arr[head];
	}
	int back() {
		if (!size) {
			return -1;
		}
		return arr[tail];
	}
	int dequeue() {
		if (size == 0) {
			return -1;
		}
		size--;
		head = (head + 1) % 10000;
		return arr[head-1];
	}
	void enqueue(int n) {
		size++;
		tail = (tail + 1) % 10000;
		arr[tail] = n;
		if (size == 1) {
			head = tail;
		}
	}
	
	bool empty() {
		return !size;
	}

};

int main() {
	int N;
	cin >> N;
	Queue s;
	for (int i{ 0 }; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> tmp;
			s.enqueue(tmp);
		}
		else if (str == "pop") {
			cout << s.dequeue() << endl;
		}
		else if (str == "front") {
			cout << s.front() << endl;
		}
		else if (str == "back") {
			cout << s.back() << endl;
		}
		else if (str == "size") {
			cout << s.size << endl;
		}
		else if (str == "empty") {
			cout << s.empty() << endl;
		}
	}
}