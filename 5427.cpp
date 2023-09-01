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
int maze[1001][1001];
int check[1001][1001];
bool visit[1001][1001];
pair<int, int>location;
int T, N, M;
int noFireZone;
int fire;
int day;
bool impossible;
queue<queue<pair<int, int>>> fireQueueQueue;
queue<queue<pair<int, int>>> charQueueQueue;
vector<pair<int, int>> initialFire;

void bfs_fire() {
	queue<pair<int, int>>q;
	while (!fireQueueQueue.front().empty()) {
		pair<int, int> tmpp = fireQueueQueue.front().front();
		fireQueueQueue.front().pop();
		//╩С
		if (tmpp.first < N - 1 && maze[tmpp.first + 1][tmpp.second] == '.') {
			q.push({ tmpp.first + 1, tmpp.second });
			maze[tmpp.first + 1][tmpp.second] = 1;
			fire++;
		}
		//го
		if (tmpp.first > 0 && maze[tmpp.first - 1][tmpp.second] == '.') {
			q.push({ tmpp.first - 1, tmpp.second });
			maze[tmpp.first - 1][tmpp.second] = 1;
			fire++;
		}
		//аб
		if (tmpp.second > 0 && maze[tmpp.first][tmpp.second - 1] == '.') {
			q.push({ tmpp.first, tmpp.second - 1 });
			maze[tmpp.first][tmpp.second - 1] = 1;
			fire++;
		}
		//©Л
		if (tmpp.second < M - 1 && maze[tmpp.first][tmpp.second + 1] == '.') {
			q.push({ tmpp.first, tmpp.second + 1 });
			maze[tmpp.first][tmpp.second + 1] = 1;
			fire++;
		}
	}
	fireQueueQueue.pop();
	fireQueueQueue.push(q);
	if (flag == false) {
		impossible = true;
		return;
	}
}

void bfs_run() {
	queue<pair<int, int>>q;
	visit[location.first][location.second] = 1;
	q.push(location);
	while (!q.empty()) {
		pair<int, int> tmpp = q.front();
		q.pop();
		if (tmpp.first < N - 1 && maze[tmpp.first + 1][tmpp.second] == '.' && visit[tmpp.first + 1][tmpp.second] == false) {
			q.push({ tmpp.first + 1, tmpp.second });
			visit[tmpp.first + 1][tmpp.second] = true;
			check[tmpp.first + 1][tmpp.second] = check[tmpp.first][tmpp.second] + 1;
		}
		if (tmpp.first > 0 && maze[tmpp.first - 1][tmpp.second] == '.' && visit[tmpp.first - 1][tmpp.second] == false) {
			q.push({ tmpp.first - 1, tmpp.second });
			visit[tmpp.first - 1][tmpp.second] = true;
			check[tmpp.first - 1][tmpp.second] = check[tmpp.first][tmpp.second] + 1;
		}
		if (tmpp.second > 0 && maze[tmpp.first][tmpp.second - 1] == '.' && visit[tmpp.first][tmpp.second - 1] == false) {
			q.push({ tmpp.first, tmpp.second - 1 });
			visit[tmpp.first][tmpp.second - 1] = true;
			check[tmpp.first][tmpp.second - 1] = check[tmpp.first][tmpp.second] + 1;
		}
		if (tmpp.second < M - 1 && maze[tmpp.first][tmpp.second + 1] == '.' && visit[tmpp.first][tmpp.second + 1] == false) {
			q.push({ tmpp.first, tmpp.second + 1 });
			visit[tmpp.first][tmpp.second + 1] = true;
			check[tmpp.first][tmpp.second + 1] = check[tmpp.first][tmpp.second] + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '@') {
				location = { i,j };
			}
		}
	}

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			if (maze[i][j] == 1) {
				initialFire.push_back({ i,j });
				fire++;
			}
			else if (maze[i][j] == -1) {
				noFireZone++;
			}

		}
	}
	queue<pair<int, int>>q0;
	for (auto i : initialFire) {
		q0.push(i);
	}
	queueQueue.push(q0);
	while (1) {
		if (impossible == true) {
			cout << -1;
			return 0;
		}
		if (N * M - noFireZone == fire || day == -1) {
			cout << day;
			return 0;
		}
		bfs();
		day++;
	}
}