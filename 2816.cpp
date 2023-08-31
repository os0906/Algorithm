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
	vector<string>v;
	int N, k1{ 0 }, k2{ 0 };
	string tmp;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i{ 0 }; i < N; i++) {
		if (v[i] == "KBS1") {
			k1 = i;
		}
		else if (v[i] == "KBS2") {
			k2 = i;
		}
	}
	if (k1 < k2) {
		for (int i{ 0 }; i < k1; i++) {
			cout << 1;
		}
		for (int i{ 0 }; i < k1; i++) {
			cout << 4;
		}
		for (int i{ 0 }; i < k2; i++) {
			cout << 1;
		}
		for (int i{ 0 }; i < k2-1; i++) {
			cout << 4;
		}
	}
	else {
		for (int i{ 0 }; i < k2; i++) {
			cout << 1;
		}
		for (int i{ 0 }; i < k1-k2; i++) {
			cout << 3;
		}
		cout << 2;
		for (int i{ 0 }; i < k1 - 1; i++) {
			cout << 4;
		}
		for (int i{ 0 }; i < k1; i++) {
			cout << 1;
		}
		for (int i{ 0 }; i < k1 - 1; i++) {
			cout << 4;
		}
	}
}