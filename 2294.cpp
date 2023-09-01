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
int N, K, tmp;
int dp[10001];
vector<int>v;int main() {
	fill_n(dp, 10001, -1);
	dp[0] = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i{ 0 }; i < N; i++) {
		for (int j = v[i]; j <= K; j++) {
			if (j % v[i] == 0) {
				dp[j] = j / v[i];
			}
			else {
				for (int k = j - j / v[i] * v[i]; k <= K; k += v[i]) {
					if (dp[k] != -1) {
						tmp = dp[k] + (j - k) / v[i];
						if (dp[j] != -1) {
							dp[j] = min(tmp, dp[j]);
						}
						else {
							dp[j] = tmp;
						}
					}
				}

			}
		}
	}
	cout << dp[K];
}