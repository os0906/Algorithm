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
//dp[i] = i일에 받을 수 있는 금액의 최댓값
int dp[16];
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, tmp1, tmp2;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp1 >> tmp2;
		v.push_back({ tmp1,tmp2 });
	}
	int max_pay = 0;
	for (int i = 0; i <= N; i++) {
		dp[i] = max(max_pay, dp[i]);
		if (v[i].first + i <= N) {
			dp[v[i].first + i] = max(dp[v[i].first + i], v[i].second + dp[i]);
		}
		max_pay = max(max_pay, dp[i]);
	}
	cout << max_pay;
}