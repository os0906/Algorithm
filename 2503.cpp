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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, s, b;
	string q;
	set<int>first{ 1,2,3,4,5,6,7,8,9 };
	set<int>second{ 1,2,3,4,5,6,7,8,9 };
	set<int>third{ 1,2,3,4,5,6,7,8,9 };

	set<int>probabillity;
	cin >> N;
	while (N--) {
		cin >> q >> s >> b;
		if (s == 0) {
			if (b == 0) {
				for (int i{ 0 }; i < 3; i++) {
					first.erase(q[i]-'0');
					second.erase(q[i] - '0');
					third.erase(q[i] - '0');
				}
			}
			if (b == 1) {
				probabillity.insert(q[0] - '0');
				probabillity.insert(q[1] - '0');
				probabillity.insert(q[2] - '0');
			}
			if (b == 2) {
				probabillity.insert(q[0] - '0');
				probabillity.insert(q[1] - '0');
				probabillity.insert(q[2] - '0');
			}
			if (b == 3) {
				first = { q[0] - '0',q[1] - '0',q[2] - '0' };
				third = { q[0] - '0',q[1] - '0',q[2] - '0' };
				first = { q[0] - '0',q[1] - '0',q[2] - '0' };
			}
		}
		else if (s == 1) {

		}
		else if (s == 2) {

		}
		else if (s == 3) {
			cout << 1;
			return;
		}
	}
}