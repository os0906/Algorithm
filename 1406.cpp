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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	stack<char> s1;
	stack<char> s2;
	cin >> str;
	for (auto i : str) {
		s1.push(i);
	}
	int M;
	char tmp;
	int size = str.length();
	int cursor{ size };
	char command;
	cin >> M;
	while (M--) {
		cin >> command;
		if (command == 'L') {
			if (cursor == 0) {}
			else {
				s2.push(s1.top());
				s1.pop();
			}
		}
		else if (command == 'D') {
			if (cursor == size) {}
			else {
				s1.push(s2.top());
				s2.pop();
			}
		}
		else if (command == 'B') {
			if (cursor == 0) {}
			else {
				s1.pop();
			}
		}
		else if (command == 'P') {
			cin >> tmp;
			s1.push(tmp);
		}
		cursor = s1.size();
		size = s1.size() + s2.size();
	}
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}

	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}
}