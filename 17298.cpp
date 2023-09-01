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
int ans[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	stack<int> s;
	vector<int> v;
	int N, tmp;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i{ N - 1 }; i >= 0; i--) {
		while (!s.empty()&&s.top()<=v[i]) {
			s.pop();
		}
		if (s.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();
		}
		s.push(v[i]);
	}
	for (int i{ 0 }; i < N; i++) {
		cout << ans[i] << ' ';
	}
}