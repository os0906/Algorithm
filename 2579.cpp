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
int arr[301];
int stair[301];
int dp(int N) {
	if (N == 0) {
		return 0;
	}
	if (N == 1) {
		arr[1] = stair[1];
		return arr[1];
	}
	if (N == 2) {
		arr[2] = dp(1) + stair[2];
		return arr[2];
	}
	else {
		if (arr[N] != 0) {
			return arr[N];
		}
		else {
			arr[N] = max(dp(N - 3) + stair[N - 1] + stair[N], dp(N - 2) + stair[N]);
			return arr[N];
		}
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		cin >> stair[i];
	}
	cout << dp(N);
}