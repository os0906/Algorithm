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
int T, N;
string X;
string str;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (cin >> X >> N) {
		str = X;
		cnt = 1;
		bool flag = false;
		do {
			if (cnt == N) {
				cout << str << ' ' << N << " = " << X << '\n';
				flag = true;
				break;
			}
			cnt++;
		} while (next_permutation(X.begin(), X.end()));
		if (flag == false) {
			cout << str << ' ' << N << " = " << "No permutation" << '\n';
		}
		
	}
}