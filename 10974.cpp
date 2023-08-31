#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
using namespace std;
int N;
int visit[10];
int arr[10];
void dfs(int cnt) {
	if (cnt == N) {
		for (int i{ 0 }; i < N; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i{ 0 }; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = i + 1;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dfs(0);
}