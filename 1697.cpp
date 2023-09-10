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
int N, K;
int dist[100001];
int visit[100001];
vector<pair<int, int>>g[100001];

void dijkstra(int start) {
	fill_n(dist, 100'001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		if (cur == K) {
			return;
		}
		int curDist = pq.top().first;

		if (cur * 2 <= 100'000 && cur != 0) {
			g[cur].push_back({ cur * 2, 1 });
		}
		if (cur > 0) {
			g[cur].push_back({ cur - 1, 1 });
		}
		if (cur < 100'000) {
			g[cur].push_back({ cur + 1, 1 });
		}

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
		g[cur].clear();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	if (N > K) {
		cout << N - K;
	}
	else if (N == K) {
		cout << 0;
	}
	else {
		dijkstra(N);
		cout << dist[K];
	}
}