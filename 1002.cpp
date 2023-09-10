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
double T, x, xx, y, yy, r1, r2;
double d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> x >> y >> r1 >> xx >> yy >> r2;
		d = sqrt(pow((x - xx), 2) + pow((y - yy), 2));
		if (d == 0) {
			if (r1 != r2) {
				cout << 0 << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (d > abs(r1 - r2) && d < r1 + r2) {
			cout << 2 << '\n';
		}
		else if (d == abs(r1 - r2) || d == r1 + r2) {
			cout << 1 << '\n';
		}
		else if (d < abs(r1 - r2) || d > r1 + r2) {
			cout << 0 << '\n';
		}
	}
}