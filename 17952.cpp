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
	int N, A, T;
	int ans{ 0 };
	bool b;
	stack<pair<int,int>>s;
	cin >> N;
	while (N--) {
		cin >> b;
		if (b == true) {
			cin >> A >> T;
			s.push({ A, T - 1 });
			if (T - 1 == 0) {
				ans += A;
				s.pop();
			}
		}
		else {
			if (!s.empty()) {
				pair<int, int>p = s.top();
				p.second--;
				s.pop();
				s.push(p);
				if (s.top().second == 0) {
					ans += s.top().first;
					s.pop();
				}
			}
		}
	}
	cout << ans;
}