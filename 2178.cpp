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
int maze[101][101];
bool visit[101][101];
int check[101][101];
string tmp;
int N, M;
int ans = 1;
queue<pair<int, int>>q;
void bfs() {
	visit[0][0] = 1;
	q.push({ 0,0 });
	while (!q.empty()) {
		pair<int, int> tmpp = q.front();
		q.pop();
		if (tmpp.first > 0 && maze[tmpp.first - 1][tmpp.second] == 1 && visit[tmpp.first - 1][tmpp.second] == false) {
			q.push({ tmpp.first - 1, tmpp.second });
			visit[tmpp.first - 1][tmpp.second] = true;
			check[tmpp.first - 1][tmpp.second] = check[tmpp.first][tmpp.second] + 1;
		}
		if (tmpp.second > 0 && maze[tmpp.first][tmpp.second - 1] == 1 && visit[tmpp.first][tmpp.second - 1] == false) {
			q.push({ tmpp.first, tmpp.second - 1});
			visit[tmpp.first][tmpp.second - 1] = true;
			check[tmpp.first][tmpp.second - 1] = check[tmpp.first][tmpp.second] + 1;
		}
		if (tmpp.first < N && maze[tmpp.first + 1][tmpp.second] == 1 && visit[tmpp.first + 1][tmpp.second] == false) {
			q.push({ tmpp.first + 1, tmpp.second});
			visit[tmpp.first + 1][tmpp.second] = true;
			check[tmpp.first + 1][tmpp.second] = check[tmpp.first][tmpp.second] + 1;
		}
		if (tmpp.second < M && maze[tmpp.first][tmpp.second + 1] == 1 && visit[tmpp.first ][tmpp.second + 1] == false) {
			q.push({ tmpp.first, tmpp.second + 1});
			visit[tmpp.first][tmpp.second + 1] = true;
			check[tmpp.first][tmpp.second + 1] = check[tmpp.first][tmpp.second] + 1;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		for (int j{ 0 }; j < M; j++) {
			maze[i][j] = tmp[j] - '0';
		}
	}
	bfs();
	cout << check[N - 1][M - 1] + 1;
}