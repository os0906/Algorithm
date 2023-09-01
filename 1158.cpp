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
}