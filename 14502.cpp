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
int N, M;
int noTomatoZone;
int tomato;
int day;
bool impossible;
queue<queue<pair<int, int>>> queueQueue;
vector<pair<int, int>> initialTomato;
void bfs() {
	bool flag = false;
	queue<pair<int, int>>q;
	while (!queueQueue.front().empty()) {
		pair<int, int> tmpp = queueQueue.front().front();
		queueQueue.front().pop();
		//╩С
		if (tmpp.first < N - 1 && maze[tmpp.first + 1][tmpp.second] == 0) {
			q.push({ tmpp.first + 1, tmpp.second });
			maze[tmpp.first + 1][tmpp.second] = 1;
			tomato++;
			flag = true;
		}
		//го
		if (tmpp.first > 0 && maze[tmpp.first - 1][tmpp.second] == 0) {
			q.push({ tmpp.first - 1, tmpp.second });
			maze[tmpp.first - 1][tmpp.second] = 1;
			tomato++;
			flag = true;
		}
		//аб
		if (tmpp.second > 0 && maze[tmpp.first][tmpp.second - 1] == 0) {
			q.push({ tmpp.first, tmpp.second - 1 });
			maze[tmpp.first][tmpp.second - 1] = 1;
			tomato++;
			flag = true;
		}
		//©Л
		if (tmpp.second < M - 1 && maze[tmpp.first][tmpp.second + 1] == 0) {
			q.push({ tmpp.first, tmpp.second + 1 });
			maze[tmpp.first][tmpp.second + 1] = 1;
			tomato++;
			flag = true;
		}
	}
	queueQueue.pop();
	queueQueue.push(q);
	if (flag == false) {
		impossible = true;
		return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			cin >> maze[i][j];
		}
	}

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			if (maze[i][j] == 2) {
				initialTomato.push_back({ i,j });
				tomato++;
			}
			else if (maze[i][j] == 1) {
				noTomatoZone++;
			}

		}
	}
	queue<pair<int, int>>q0;
	for (auto i : initialTomato) {
		q0.push(i);
	}
	queueQueue.push(q0);
	while (1) {
		if (impossible == true) {
			cout << N * M - tomato - noTomatoZone;
			return 0;
		}
		if (N * M - noTomatoZone == tomato || day == -1) {
			cout << day;
			return 0;
		}
		bfs();
		day++;
	}
}