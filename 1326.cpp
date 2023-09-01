#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
vector<int>bridge(10001);
vector<int>predecessor(10001, -1);
vector<vector<int>>graph(10001, vector<int>());
bool visit[10001];
int bfs(int start,int end) {
	queue<int> q;
	q.push(start);
	predecessor[start] = 0;
	visit[start] = 1;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (tmp == end) {
			int cur = end;
			int length = 0;
			while (predecessor[cur] != 0) {
				length++;
				cur = predecessor[cur];
			}
			return length;
		}
		for (int i{ 0 }; i < graph[tmp].size(); i++) {
			if (visit[graph[tmp][i]] == 0) {
				q.push(graph[tmp][i]);
				visit[graph[tmp][i]] = 1;
				predecessor[graph[tmp][i]] = tmp;
			}
		}
	}
	return -1;
}
int main() {
	int N, s, e;
	int tmp;
	cin >> N;
	bridge.push_back(0);
	for (int i{ 1 }; i <= N; i++) {
		cin >> tmp;
		bridge[i] = tmp;
	}
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			if (i != j) {
				int distance = abs(i - j);
				if (distance >= bridge[i] && distance % bridge[i]==0){
					graph[i].push_back(j);
				}
			}
		}
	}
	cin >> s >> e;
	cout << bfs(s, e);
}