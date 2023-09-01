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
	queue<int>q;
	stack<int>s;
	int N, tmp;
	cin >> N;
	int target = 1;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		q.push(tmp);
	}
	while (1) {
		if (q.empty() && s.empty()) {
			cout << "Nice";
			return 0;
		}
		if (!s.empty()) {
			if (s.top() == target) {
				target++;
				s.pop();
				continue;
			}
		}
		if (!q.empty()) {
			while (q.front() != target) {
				tmp = q.front();
				q.pop();
				if ((!s.empty() && tmp > s.top()) || q.empty()) {
					cout << "Sad";
					return 0;
				}
				s.push(tmp);
			}
			q.pop();
			target++;
		}
	}
}