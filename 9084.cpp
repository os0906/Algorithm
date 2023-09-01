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
int T, N, K, tmp;
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int>v;
		v.push_back(0);
		for (int i{ 0 }; i < N; i++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		cin >> K;
		dp[0] = 1;
		for (int i{ 1 }; i <= N; i++) {
			for (int j = v[i]; j <= K; j++) {
				dp[j] += dp[j - v[i]];
			}
		}
		cout << dp[K] << '\n';
		fill_n(dp, 10001, 0);
	} 
	
}