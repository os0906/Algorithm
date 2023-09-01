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
int idx;
vector<int>primes;
int find(int n,int I) {
	for (int i{ 0 }; i <= I; i++) {
		if (primes[i] == n) {
			return primes[i];
		}
	}
	return 0;
}
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
	for (int i = 2; i < 10001; i++) {
		if (arr[i] == 0) {
			primes.push_back(i);
		}
	}
	int T;
	int tmp;
	cin >> T;
	while (T--) {
		cin >> tmp;
		for (int i{ 0 }; i < primes.size(); i++) {
			if (tmp / 2 <= primes[i]) {
				idx = i;
				break;
			}
		}
		for (int i{ idx }; i < primes.size(); i++) {
			if (find(tmp - primes[i], i) != 0) {
				cout << find(tmp - primes[i], i) << ' ' << primes[i] << '\n';
				break;
			}
		}
	}
}