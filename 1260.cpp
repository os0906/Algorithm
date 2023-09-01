#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>> v(1001);
bool dfsVisit[1001];
bool bfsVisit[1001];
queue<int>q;
void dfs(int n) {
		cout << n << ' ';
		dfsVisit[n] = true;
	for (int i{ 0 }; i < v[n].size(); i++) {
		if (dfsVisit[v[n][i]] == false)
			dfs(v[n][i]);
	}
}
void bfs(int n) {
		q.push(n);
		bfsVisit[n] = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << ' ';
		for (int i{ 0 }; i < v[tmp].size(); i++) {
			if (bfsVisit[v[tmp][i]] == false) {
				q.push(v[tmp][i]);
				bfsVisit[v[tmp][i]] = true;
			}
		}
	}

}
int main() {
	int N, M, V, tmp1, tmp2;
	cin >> N >> M >> V;
	for (int i{ 0 }; i < M; i++) {
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	for (int i{ 0 }; i < v.size(); i++) {
		if (v[i].size() != 0) {
			sort(v[i].begin(), v[i].end());
		}
	}
	dfs(V);
	cout << '\n';
	bfs(V);
}