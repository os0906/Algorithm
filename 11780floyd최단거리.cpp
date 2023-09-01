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
int dist[101][101];
int from[101][101];
int n, m, a, b, c;
vector<int>path[101][101];
//최단경로 기록법
void rec(int i, int j, vector<int>& path) {
	// rec(i, j, path): i -> j 경로를 path에 저장

	if (from[i][j] == -1) {
		path.push_back(i);
		path.push_back(j);
		return;
	}

	int w = from[i][j];
	rec(i, w, path);
	path.pop_back();
	rec(w, j, path);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
			from[i][j] = -1;
		}
	}
	while (m--) {
		cin >> a >> b >> c;
		//시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
		if (dist[a][b] > c)
			dist[a][b] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] == INF || dist[k][j] == INF) {
					continue;
				}
				
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					from[i][j] = k;
				}
					
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			rec(i, j, path[i][j]);
			if (dist[i][j] == INF || i == j)
				cout << "0 ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF && i != j) {
				cout << path[i][j].size() << ' ';
			}
			for (int k = 0; k < path[i][j].size(); k++) {
				if (dist[i][j] == INF || i == j) {
					cout << "0 ";
					break;
				}
				else
					cout << path[i][j][k] << " ";
			}
			cout << "\n";
		}
	}
}