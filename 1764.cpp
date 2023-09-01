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
	int N, M;
	string tmp;
	cin >> N >> M;
	set<string> s1;
	set<string> s2;
	while (N--) {
		cin >> tmp;
		s1.insert(tmp);
	}
	while (M--) {
		cin >> tmp;
		if (s1.find(tmp) != s1.end()) {
			s2.insert(tmp);
		}
	}
	cout << s2.size() << '\n';
	for (string i : s2) {
		cout << i << '\n';
	}
}