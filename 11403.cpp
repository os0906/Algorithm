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
int matrix[101][101];
bool visit[101];
int tmp;
vector<vector<int>>g(101);

void bfs(int n) {
	queue<int>q;
	q.push(n);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i{ 0 }; i < g[tmp].size(); i++) {
			if (visit[g[tmp][i]] == false) {
				q.push(g[tmp][i]);
				visit[g[tmp][i]] = true;
				matrix[n][g[tmp][i]] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			cin >> tmp;
			if (tmp == 1) {
				g[i].push_back(j);
			}
		}
	}

	for (int i{ 1 }; i <= N; i++) {
		bfs(i);
		fill_n(visit, 101, 0);
	}
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
}