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
//�ߺ� �ִ� ����
void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[cnt] = i;
		dfs(cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	dfs(0);
}