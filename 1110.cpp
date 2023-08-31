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
	int N;
	int cnt{ 0 }, n1, n2;
	cin >> N;
	int org{ N };
	while (1) {
		cnt++;
		n1 = N / 10;
		n2 = N % 10;
		N = n2 * 10 + (n1 + n2) % 10;
		if (N == org) {
			cout << cnt;
			return 0;
		}
	}

}