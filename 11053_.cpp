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
int dp[1010];
int arr[1010];
int N, tmp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		cin >> arr[i];
	}
	int max_length = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--){
			if (arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		max_length = max(dp[i], max_length);
	}
	cout << max_length;
}