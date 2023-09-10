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
	cin.tie(NULL); cout.tie(NULL);
	for (int i{ 1 }; i <= 10000; i++) {
		bool flag = false;
		for (int j{ 1 }; j < i; j++) {
			int sum{ 0 };
			int tmp = j;
			for (int k = j; k> 0; k /= 10) {
				sum += k % 10;
			}
			if (sum + j == i) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << i << '\n';
		}
	}
}