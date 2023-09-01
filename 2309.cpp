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
	vector<int>v;
	int n;
	for (int i{ 0 }; i < 9; i++) {
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (int i{ 0 }; i < 3;i++) {
		for (int j{ i + 1 }; j < 4;j++) {
			for (int k{ j + 1 }; k < 5; k++) {
				for (int l{ k + 1 }; l < 6; l++) {
					for (int m{ l + 1 }; m < 7; m++) {
						for (int n{ m + 1 }; n < 8; n++) {
							for (int o{ n + 1 }; o < 9; o++) {
								if (v[i] + v[j] + v[k] + v[l] + v[m] + v[n] + v[o] == 100) {
									cout << v[i] << endl << v[j] << endl << v[k] << endl << v[l] << endl << v[m] << endl << v[n] << endl << v[o];
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
}