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
	int N, tmp, ans{ 0 };
	cin >> N;
	vector<int>v;
	vector<int>v1;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	if (N == 3) {
		v1.push_back(v[0]);
		v1.push_back(v[2]);
		v1.push_back(v[1]);
		for (int i{ 1 }; i < N; i++) {
			ans += abs(v1[i - 1] - v1[i]);
		}
		cout << ans;
		return 0;
	}
	if (N % 2) {
		v1.push_back(v[N / 2]);
	}
	for (int i{ 0 }; i < N / 2; i++) {
		
		v1.push_back(v[i]);
		if (N % 2 == 0 && i == N / 2 - 1) {
			v1.insert(v1.begin(), v[N - 1 - i]);
			break;
		}
		v1.push_back(v[N - 1 - i]);

	}

	for (int i{ 1 }; i < N; i++) {
		ans += abs(v1[i - 1] - v1[i]);
	}
	cout << ans;
}