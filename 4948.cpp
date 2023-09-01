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
int arr[246913] = { 0, };
int main() {
	arr[1] = 1;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i < 246913; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j * i < 246913; j++) {
				arr[i * j] = 1;
			}
		}
	}
	int N;
	cin >> N;
	while (N != 0) {
		int ans{ 0 };
		for (int i{ N + 1 }; i <= 2 * N; i++) {
			if (arr[i] == 0) {
				ans++;
			}
		}
		cout << ans << '\n';
		cin >> N;
	}
}