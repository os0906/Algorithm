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

int gcd(int n1, int n2) {
	if (n1 % n2 == 0) {
		return n2;
	}
	else {
		return gcd(n2, n1 % n2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, tmp, prev{ 0 };
	
	int s{ 1'000'000'000 }, b{ 1 }, sum{ 0 };
	cin >> N;
	vector <int>v;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		if (i != 0) {
			v.push_back(tmp - prev);
			sum += tmp - prev;
		}
		prev = tmp;
	}
	sort(v.begin(), v.end(), greater<int>());
	int gtmp{ gcd(v[0],v[1]) };
	for (int j{ 1 }; j < v.size() - 1; j++) {
		gtmp = gcd(gtmp, v[j + 1]);
	}
	cout << sum / gtmp - N + 1;
}