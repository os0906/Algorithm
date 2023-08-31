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
struct compare {
	bool operator()(int n1, int n2) {
		if (abs(n1) == abs(n2)) {
			return n1 > n2;
		}
		else {
			return abs(n1) > abs(n2);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, tmp;
	priority_queue<int, vector<int>, compare> q;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		if (tmp == 0) {
			if (q.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << q.top() << endl;
				q.pop();
			}
		}
		else {
			q.push(tmp);
		}
	}
}