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
int arr[10001] = { 0, };
int main() {
	arr[1] = 1;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i < 10001; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j * i < 10001; j++) {
				arr[i * j] = 1;
			}
		}
	}
	int M, N;
	cin >> M >> N;
	bool flag{ false };
	int ans{ -1 };
	int sum{ 0 };
	for (int i{ M }; i <= N; i++) {
		if (arr[i] == 0) {
			sum += i;
			if (flag == false) {
				ans = i;
			}
			flag = true;
		}
	}
	if (flag == true) {
		cout << sum << '\n';
	}
	cout << ans;
}