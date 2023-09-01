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
int N, tmp;
int memo[1001];
int MAX[1001];
vector<int>v;

int dp(int size) {
	if (size == 1) {
		memo[1] = v[1];
		return memo[1];
	}
	if (memo[size] == 0) {
		for (int i{ 1 }; i <= size; i++) {
			if (i == 1) {
				MAX[size] = size * dp(1);
			}
			else if (i == size) {
				MAX[size] = max(MAX[size], v[size]);
			}
			else {
				MAX[size] = max(MAX[size], dp(i) + dp(size - i));
			}
		}
		memo[size] = MAX[size];
		return memo[size];
	}
	else {
		return memo[size];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	v.push_back(0);
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	cout << dp(N);
}