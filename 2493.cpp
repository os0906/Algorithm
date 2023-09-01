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
	int N, tmp;
	cin >> N;
	stack<pair<int, int>>s;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		while (!s.empty()) {
			if (s.top().first > tmp) {
				cout << s.top().second << ' ';
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << '0' << ' ';
		}
		s.push({ tmp,i + 1 });
	}
}