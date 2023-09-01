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
#define INF 2'147'483'647
using namespace std;
int T, n, d, c, a, b, s;
int dist[10001];


void dijkstra(int start, vector<pair<int, int>>g[]) {
	fill_n(dist, 10001, INF);
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
	cin >> T;
	while (T--) {
		vector<pair<int, int>>g[10001];
		cin >> n >> d >> c;
		while (d--) {
			cin >> a >> b >> s;
			g[b].push_back({ a,s });
		}
		dijkstra(c, g);
		int sum = 0;
		int MAX = -1;
		for (int i{ 1 }; i <= n; i++) {
			if (dist[i] != INF) {
				sum++;
				MAX = max(dist[i], MAX);
			}
		}
		cout << sum << ' ' << MAX << '\n';
	}
}