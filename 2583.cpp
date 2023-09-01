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
int N, M, K;
int g[100][100];
bool visit[100][100];
int MAx;
pair<int, int>leftdown;
pair<int, int>rightup;
vector<int>areas;
int area;
void dfs(int x, int y) {
	area++;
	visit[y][x] = true;
	if (x > 0 && g[y][x - 1] == 1 && visit[y][x - 1] == false) {
		dfs(x - 1, y);
	}
	if (y > 0 && g[y - 1][x] == 1 && visit[y - 1][x] == false) {
		dfs(x, y - 1);
	}
	if (x < N - 1 && g[y][x + 1] == 1 && visit[y][x + 1] == false) {
		dfs(x + 1, y);
	}
	if (y < M - 1 && g[y + 1][x] == 1 && visit[y + 1][x] == false) {
		dfs(x, y + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> K;
	fill_n(&g[0][0], 100 * 100, 1);
	for (int i{ 0 }; i < K; i++) {
		cin >> leftdown.first >> leftdown.second >> rightup.first >> rightup.second;
		for (int x{ leftdown.first }; x < rightup.first; x++) {
			for (int y{ leftdown.second }; y < rightup.second; y++) {
				g[M - 1 - y][x] = 0;
			}
		}
	}

	for (int i{ 0 }; i < M; i++) {
		for (int j{ 0 }; j < N; j++) {
			if (g[i][j] == 1 && visit[i][j] == false) {
			    area = 0;
				dfs(j, i);
				areas.push_back(area);
			}
		}
	}
	sort(areas.begin(), areas.end());
	cout << areas.size() << '\n';
	for (auto i : areas) {
		cout << i << ' ';
	}
}