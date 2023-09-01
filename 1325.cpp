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
int N, M, tmp1, tmp2;
vector<vector<int>>g(10001);
vector<int>v;
int visit[10001];
int ans;
int Max;
void dfs(int n) {
	ans++;
	visit[n] = true;
	for (int i{ 0 }; i < g[n].size(); i++) {
		if (visit[g[n][i]] == false) {
			dfs(g[n][i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i{ 0 }; i < M; i++) {
		cin >> tmp1 >> tmp2;
		g[tmp2].push_back(tmp1);
	}
	for (int i{ 1 }; i <= N; i++) {
		dfs(i);
		if (Max < ans) {
			v.clear();
			v.push_back(i);
			Max = max(Max, ans);
		}
		else if (Max == ans) {
			v.push_back(i);
		}
		ans = 0;
		fill_n(visit, 10001, 0);
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i << ' ';
	}
}