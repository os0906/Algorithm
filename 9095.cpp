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
int memo[11];
int dp(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 4;
	}
	else {
		if (memo[n] == 0) {
			memo[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
		}
		return memo[n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n;
	cin >> T;
	for (int i{ 0 }; i < T; i++) {
		cin >> n;
<<<<<<< HEAD
		cout << dp(n) << '\n';
=======
		cout << dp(n) << endl;
>>>>>>> ff3643f445500a4356dba7142f1b392199b4ac8b
	}
}