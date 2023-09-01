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
	char tmp;
	int N; cin >> N;
	vector<vector<bool>>v;
	int column{ 0 }, row{ 0 };
	for (int i{ 0 }; i < N; i++) {
		vector<bool> vtmp;
		v.push_back(vtmp);
		for (int j{ 0 }; j < N; j++) {
			cin >> tmp;
			if (tmp == '.') {
				v[i].push_back(true);
			}
			else {
				v[i].push_back(false);
			}
		}
	}
	for (int i{ 0 }; i < N; i++) {
		int cnt{ 0 };
		for (int j{ 0 }; j < N; j++) {
			if (v[i][j]==true) {
				cnt++;
				if (cnt == 2) {
					column++;
				}
			}
			else {
				cnt = 0;
			}
		}
	}
	for (int j{ 0 }; j < N; j++) {
		int cnt{ 0 };
		for (int i{ 0 }; i < N; i++) {
			if (v[i][j] == true) {
				cnt++;
				if (cnt == 2) {
					row++;
				}
			}
			else {
				cnt = 0;
			}
		}
	}
	cout << column <<' '<< row;
}