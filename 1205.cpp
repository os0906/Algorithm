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
	int N, score, tmp, P;
	cin >> N >> score >> P;
	vector<int>v(50, { -1, });
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v[i] = tmp;
	}
	if (N == 0) {
		cout << 1;
		return 0;
	}
	for (int i{ 0 }; i < N; i++) {
		if (score >= v[i]) {
			if (score == v[i] && score == v[N - 1] && N == P) {
				cout << -1;
				return 0;
			}
			else if (i + 1 <= P) {
				cout << i + 1;
				return 0;
			}
		}
		if (i == N - 1&&N-P!=0) {
			cout << i+2;
			return 0;
		}
		else if (i==N-1) {
			cout << -1;
			return 0;
		}
	}
}