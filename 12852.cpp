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
int N;
int visit[1000001];
int memo[1000001];
vector<int> v[1000001];
queue<int> q;
void bfs(int start) {
	visit[start] = true;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i : v[cur]) {
			if(!visit)
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i{ 1 }; i < N; i++) {
		if (i * 3 <= N) {
			v[i].push_back(i * 3);
		}
		if (i * 2 <= N) {
			v[i].push_back(i * 2);
		}
		if (i + 1 <= N) {
			v[i].push_back(i + 1);
		}
	}
	dfs(1, 0);
	cout << memo[N];

}