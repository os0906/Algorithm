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
int V, E, K, u, v, w;
int dist[20001];
vector<pair<int, int>>g[20001];

void dijkstra(int start) {
	fill_n(dist, V + 1, INF);
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
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> K;

	while (E--) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
	dijkstra(K);
	for (int i{ 1 }; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
}