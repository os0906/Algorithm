#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int num[1001];
void dp(int n) {
	num[1] = 1;
	num[2] = 2;
	if (n > 2) {
		for (int i = 3; i <= n; i++) {
			num[i] = (num[i - 1] + num[i - 2]) % 10007;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	dp(N);
	cout << num[N];
}