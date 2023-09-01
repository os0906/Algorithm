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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, L, tmp, ans{ 0 };
	vector<int>v;
	cin >> N >> L;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int ltmp = L;
	for (int i{ 0 }; i < N - 1; i++) {
		if (ltmp > v[i + 1] - v[i]) {
			ltmp -= (v[i + 1] - v[i]);
		}
		else {
			ans++;
			ltmp = L;
		}
	}
	ans++;
	cout << ans;
}