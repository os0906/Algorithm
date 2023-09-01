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
#define INF 987654321
using namespace std;
int N, M, X, u, v, w;
int distFrom[1001];
int distTo[1001];
priority_queue<int>pq;
vector<pair<int, int>>gFrom[1001];
vector<pair<int, int>>gTo[1001];

void dijkstra(int start,int dist[], vector<pair<int, int>> g[]) {
	fill_n(dist, N + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();
		if (dist[cur] < curDist) continue;
		for (int i{ 0 }; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int nextDist = g[cur][i].second;
			if (dist[next] > curDist + nextDist) {
				dist[next] = curDist + nextDist;
				pq.push({ curDist + nextDist, next });
			}
		}
	}
}int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;

	while (M--) {
		cin >> u >> v >> w;
		gFrom[u].push_back({ v,w });
		gTo[v].push_back({ u,w });
	}
	dijkstra(X, distFrom, gFrom);
	dijkstra(X, distTo, gTo);
	for (int i{ 1 }; i <= N; i++) {
		pq.push({ distFrom[i] + distTo[i] });
	}
	cout << pq.top();
}