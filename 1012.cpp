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
int T, M, N, K, x, y;
int g[50][50];
int visit[50][50];

void dfs(int x, int y) {
	visit[y][x] = true;
	if (x > 0 && g[y][x - 1] == 1 && visit[y][x - 1] == false) {
		dfs(x - 1, y);
	}
	if (y > 0 && g[y - 1][x] == 1 && visit[y - 1][x] == false) {
		dfs(x, y - 1);
	}
	if (x < M - 1 && g[y][x + 1] == 1 && visit[y][x + 1] == false) {
		dfs(x + 1, y);
	}
	if (y < N - 1 && g[y + 1][x] == 1 && visit[y + 1][x] == false) {
		dfs(x, y + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		fill_n(&visit[0][0], 50 * 50, 0);
		fill_n(&g[0][0], 50 * 50, 0);
		int area = 0;
		cin >> M >> N >> K;
		while (K--) {
			cin >> x >> y;
			g[y][x] = 1;
		}

		for (int i{ 0 }; i < N; i++) {
			for (int j{ 0 }; j < M; j++) {
				if (g[i][j] == 1 && visit[i][j] == false) {
					area++;
					dfs(j, i);
				}
			}
		}
		cout << area << '\n';
	}
	
}