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
int dist[801][801];
int n, e, a, b, c, v1, v2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
	while (e--) {
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	cin >> v1 >> v2;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] == INF || dist[k][j] == INF)continue;
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	priority_queue<int,vector<int>,greater<>>pq;
	if (v1 == 1 && v2 == n) {
		if(dist[v1][v2]!=INF)
			pq.push(dist[v1][v2]);
	}
	else if (v2 == n) {
		if (dist[1][v1] != INF && dist[v1][n] != INF)
			pq.push(dist[1][v1] + dist[v1][n]);
	}
	else if (v1 == 1) {
		if (dist[1][v2] != INF && dist[v2][n] != INF)
			pq.push(dist[1][v2] + dist[v2][n]);
	}
	else {
		if (dist[1][v1] != INF && dist[v1][v2] != INF && dist[v2][n] != INF)
			pq.push(dist[1][v1] + dist[v1][v2] + dist[v2][n]);
		if (dist[1][v2] != INF && dist[v2][v1] != INF && dist[v1][n] != INF)
			pq.push(dist[1][v2] + dist[v2][v1] + dist[v1][n]);
	}
	if (pq.empty()) {
		cout << -1;
	}
	else {
		cout << pq.top();
	}
}