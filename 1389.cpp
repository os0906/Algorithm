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
int N, M, tmp1, tmp2;vector<vector<int>>g(101);
int pathLength[101];
vector<int>v(101);
int visit[10001];
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

int getMinPerson() {
	int bacon = v[1]; // 케빈 베이컨의 수  
	int person = 1; // 최소 케빈 베이컨의 수를 갖는 사람 번호 

	for (int i = 2; i <= N; i++) {
		if (bacon > v[i]) {
			bacon = v[i];
			person = i;
		}
	}

	return person;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i{ 0 }; i < M; i++) {
		cin >> tmp1 >> tmp2;
		g[tmp1].push_back(tmp2);
		g[tmp2].push_back(tmp1);
	}
	for (int i{ 1 }; i <= N; i++) {
		bfs(i);
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			v[i] += pathLength[j];
		}
		fill_n(visit, N + 1, 0);
		fill_n(pathLength, N + 1, 0);
	}
	cout << getMinPerson();
}