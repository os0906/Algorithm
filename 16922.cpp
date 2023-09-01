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
// 중복 있는 순열
using namespace std;
int N;
int cnt;
int arr[21];
int coin[4] = { 1,5,10,50 };
int ans{ 0 };
bool check[1001];
void dfs(int start, int cnt) {
	if (cnt == N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += coin[arr[i] % 4];
		}
		if (check[sum] == false) {
			ans++;
			check[sum] = true;
		}
		return;
	}

	for (int i = start; i < 4; i++) {
		arr[cnt] = i;
		dfs(i, cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dfs(0, 0);
	cout << ans;
}