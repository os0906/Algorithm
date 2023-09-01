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
			// i���� j�� ���� ��ΰ� �ִµ� ���� �湮���� ���� ��� 
			if (visit[g[tmp][i]] == false) {
				// �湮 ó�� 
				visit[g[tmp][i]] = true;
				q.push(g[tmp][i]);
				// i���� j������ ��� ���� ���� 
				pathLength[g[tmp][i]] = pathLength[tmp] + 1;
			}
		}
	}
}

int getMinPerson() {
	int bacon = v[1]; // �ɺ� �������� ��  
	int person = 1; // �ּ� �ɺ� �������� ���� ���� ��� ��ȣ 

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