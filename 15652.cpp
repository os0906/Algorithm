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
int N, M;
int cnt;
int arr[9];
//중복 있는 조합
void dfs(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num - 1; i <= N; i++) {
		if (i != 0) {
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	dfs(1, 0);
}