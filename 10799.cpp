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
	string stream;
	cin >> stream;
	int ans{ 0 };
	stack<char>s;
	for (int i{ 0 }; i < stream.length(); i++) {
		if (stream[i] == '(') {
			s.push('(');
		}
		else {
			if (stream[i - 1] == '(') {
				s.pop();
				ans += s.size();
			}
			else {
				s.pop();
				ans++;
			}
		}
	}
	cout << ans;
}