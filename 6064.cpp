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

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	int N, M, x, y;
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;
		int end = lcm(M, N);
		int ans{ -1 };
		for (int i{ x }; i <= end; i += M) {
			int Y = i % N;
			if (Y == 0) {
				Y = N;
			}
			if (Y == y) {
				ans = i;
				break;
			}
		}	
		cout<<ans<<'\n';
	}
}