/*#include <algorithm>
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
//가중치 X - BFS 
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i{ 0 }; i < g[tmp].size(); i++) {
			// i에서 j로 가는 경로가 있는데 아직 방문하지 않은 경우 
			if (visit[g[tmp][i]] == false) {
				// 방문 처리 
				visit[g[tmp][i]] = true;
				q.push(g[tmp][i]);
				// i에서 j까지의 경로 길이 갱신 
				pathLength[g[tmp][i]] = pathLength[tmp] + 1;
			}
		}
	}
}
//가중치 O - dijkstra O(V*ElogV)
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
//가중치 O - floyd warshall O(V^3)
for (int k = 1; k <= n; k++) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][k] == INF || dist[k][j] == INF)continue;
			if (dist[i][k] + dist[k][j] < dist[i][j])
				dist[i][j] = dist[i][k] + dist[k][j];
		}
	}
}
*/