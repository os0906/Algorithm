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
// 중복순열이 아닌, 중복조합
using namespace std;
int N, M, tmp;
int cnt;
vector<int>v;
int arr[9];
void dfs(int start, int cnt) {
	if (cnt == M) {
		int sum = 0;
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < N; i++) {
		arr[cnt] = v[i];
		dfs(i, cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	dfs(0, 0);
}