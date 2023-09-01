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
int n, m, r, u, v, w;
pair<int,int> dist[101];
int items[101];
priority_queue<int>PQ;
vector<pair<int, int>>g[101];

int dijkstra(int start) {
	for (int i = 1; i <= n; i++) {
		dist[i].first = INF;
		dist[i].second = 0;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
	pq.push({ 0, start });
	dist[start].first = 0;
	dist[start].second = items[start];
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();
		if (dist[cur].first < curDist) continue;
		for (int i{ 0 }; i < g[cur].size(); i++) {
			int next = g[cur][i].first;
			int nextDist = g[cur][i].second;
			int nextItem = items[g[cur][i].first];
			if (dist[next].first > curDist + nextDist && m >= curDist + nextDist) {
				dist[next].first = curDist + nextDist;
				dist[next].second += nextItem;
				pq.push({ curDist + nextDist, next });
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += dist[i].second;
		
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}
	while (r--) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
		g[v].push_back({ u,w });
	}
	for (int i = 1; i <= n; i++) {
		PQ.push(dijkstra(i));
	}
	cout << PQ.top();
}