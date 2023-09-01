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
unsigned long long int memo[91];
unsigned long long int dp(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		if (memo[n] == 0) {
			memo[n] = dp(n - 1) + dp(n - 2);
		}
		return memo[n];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << dp(N);
}