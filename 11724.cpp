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
bool visit[1001];
int ans;
vector<vector<int>>v(1001);
void dfs(int n) {
	visit[n] = true;
	for (int i{ 0 }; i < v[n].size(); i++) {
		if (visit[v[n][i]] == false) {
			dfs(v[n][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	while (M--) {
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}

	for (int i{ 1 }; i <= N; i++) {
		if (visit[i] == false) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;
}