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
int N, M, a, b, c;
int par[100001];
int visit[100001];
vector<int>g[100001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<>>pq;
void dfs(int x) {
	visit[x] = 1;
	for (int i{ 0 }; i < g[x].size(); i++) {
		if (visit[g[x][i]] == false) {
			dfs(g[x][i]);
		}
	}
}
bool isSpanningTree() {
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			return false;
		}
	}
	return true;
}

int Find(int x) {
	if (x == par[x]){
		return x;
	}
	else {
		int p = Find(par[x]);
		par[x] = p;
		return p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		par[y] = x;
	}
}
bool valid(int x, int y) {
	x = Find(x);
	y = Find(y);
	return x == y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	long long int sum{ 0 };
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		g[a].push_back(b);
		g[b].push_back(a);
		pq.push({ c, {a, b} });
		sum += c;
	}
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}

	int cnt = 0;
	long long int ans = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int y = pq.top().second.second;
		int x = pq.top().second.first;
		pq.pop();
		if (!valid(x, y)) {
			ans += cost;
			Union(x, y);
			if (++cnt == N - 1) break;
		}
	}
	dfs(a);
	if (isSpanningTree()) {
		cout << sum - ans;
	}
	else {
		cout << -1;
	}
	
}