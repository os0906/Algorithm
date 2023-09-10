#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
using namespace std;
int arr[7];
int X;
int digit;
int visit[7];
priority_queue<int, vector<int>, greater<>>pq;
vector<int>v;

void dfs(int count) {
	if (count == digit) {
		int ans = 0;
		for (int i{ 0 }; i < digit; i++) {
			ans += pow(10, i) * arr[i];
		}
		if (ans > X) {
			pq.push(ans);
		}
		return;
	}

	for (int i{ 0 }; i < digit; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[i] = v[count];
			dfs(count + 1);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X;
	for (int i{ X }; i!=0; i/=10) {
		v.push_back(i % 10);
	}
	digit = v.size();
	dfs(0);
	if (pq.empty()) {
		cout << 0;
	}
	else {
		cout << pq.top();
	}
}