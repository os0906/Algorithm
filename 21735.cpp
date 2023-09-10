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
int N, M, tmp;
vector<int>v;
priority_queue<int>pq;
void dfs(int count,int idx/*idx of v*/,int snow) {
	if (count == M || idx == v.size() - 1) {
		pq.push(snow);
		return;
	}
	if (idx + 1 <= v.size()) {
		dfs(count + 1, idx + 1, snow + v[idx + 1]);
	}
	if (idx + 2 <= v.size()) {
		dfs(count + 1, idx + 2, snow / 2 + v[idx + 2]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	v.push_back(0);
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	dfs(0, 0, 1);
	cout << pq.top();
}