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
int N;
vector<vector<int>>arr{ 15,vector<int>(15,1) };
int Left;
int qLeft;
int ans;
void solve(int x, int y) {
	if (Left < qLeft) {
		return;
	}
	for (int i{ 0 }; i < N; i++) {
		if (arr[x][i]) {
			arr[x][i] = 0;
			Left--;
		}
	}
	for (int i{ 0 }; i < N; i++) {
		if (arr[i][y]) {
			arr[i][y] = 0;
			Left--;
		}
	}
	for (int i{ 0 }; i < min(N - x, N - y); i++) {
		if (arr[x + i][y + i]) {
			arr[x + i][y + i] = 0;
			Left--;
		}
		
	}
	for (int i{ 0 }; i < min(x, y); i++) {
		if (arr[x - i][y - i]) {
			arr[x - i][y - i] = 0;
			Left--;
		}
	}
	for (int i{ 0 }; i < min(N - x, y); i++) {
		if (arr[x + i][y - i]) {
			arr[x + i][y - i] = 0;
			Left--;
		}
	}
	for (int i{ 0 }; i < min(x, N - y); i++) {
		if (arr[x - i][y + i]) {
			arr[x - i][y + i] = 0;
			Left--;
		}
	}
	arr[x][y] = 2;
	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 2;
				qLeft--;
				if (qLeft == 0) {
					ans++;
					return;
				}
				solve(i, j);
			}
		}
		cout << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	Left = N * N;
	qLeft = N;
	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			fill_n(&arr[0][0], N * N, 1);
			Left = N * N;
			qLeft = N;
			solve(i, j);
		}
	}
	cout << ans;
}