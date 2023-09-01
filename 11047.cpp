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
int n, k, tmp, ans;
vector<int>coin;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		coin.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		if (k == 0) {
			break;
		}
		if (k / coin[n - 1 - i]>0) {
			ans += k / coin[n - 1 - i];
			k -= k / coin[n - 1 - i] * coin[n - 1 - i];
		}
	}
	cout << ans;
}