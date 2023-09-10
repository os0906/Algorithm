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
int weight = 0;
int arr[9];
int visit[9];
int ans;
int N, K, tmp;
vector<int>v;

void dfs(int count) {
	if (count == N) {
		int cnt = 0;
		for (int i{ 0 }; i < N; i++) {
			cnt += arr[i];
			cnt -= K;
			if (cnt < 0) {
				return;
			}
		}
		ans++;
		return;
	}

	for (int i{ 0 }; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[i] = v[count];
			dfs(count + 1);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	dfs(0);
	cout << ans;
}