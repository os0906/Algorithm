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
struct cmp1 {
	bool operator()(string& a, string& b) {
		return a.length() > b.length();

	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	string str;
	while (T--) {
		int N;
		cin >> N;
		priority_queue<string,vector<string>,cmp>pq;
		while (N--) {
			cin >> str;
			pq.push(str);
		}
		while (!pq.empty()) {
			string tmp = pq.top();
			pq.pop();
			if (pq.empty()) {
				break;
			}
			if (pq.top().find(tmp) == string::npos) {
				continue;
			}
			else {
				cout << "NO" << '\n';
				break;
			}
		}
		if (pq.empty()) {
			cout << "YES" << '\n';
		}
	}
}