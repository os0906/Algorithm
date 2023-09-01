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
int N;
int Max;
int land[100][100];
int g[100][100];
bool visit[100][100];
int MAx;

void dfs(int x, int y) {
	visit[x][y] = true;
	if (x > 0 && g[x - 1][y] == 1 && visit[x - 1][y] == false) {
		dfs(x - 1, y);
	}
	if (y > 0 && g[x][y - 1] == 1 && visit[x][y - 1] == false) {
		dfs(x, y - 1);
	}
	if (x < N - 1 && g[x + 1][y] == 1 && visit[x + 1][y] == false) {
		dfs(x + 1, y);
	}
	if (y < N - 1 && g[x][y + 1] == 1 && visit[x][y + 1] == false) {
		dfs(x, y + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			cin >> land[i][j];
			Max = max(land[i][j], Max);
		}
	}

	for (int i{ 0 }; i <= Max; i++) {
		fill_n(&visit[0][0], 100 * 100, 0);
		for (int j{ 0 }; j < N; j++) {
			for (int k{ 0 }; k < N; k++) {
				if (land[j][k] <= i) {
					g[j][k] = 0;
				}
				else {
					g[j][k] = 1;
				}
			}
		}
		int ans = 0;
		bool first = false;
		for (int j{ 0 }; j < N; j++) {
			for (int k{ 0 }; k < N; k++) {
				if (g[j][k] == 1 && visit[j][k] == false) {
					dfs(j, k);
					ans++;
				}
			}
		}
		MAx = max(ans, MAx);
	}
	cout << MAx;
}