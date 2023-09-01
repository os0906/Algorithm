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
	int N, M;
	string domain, pw;
	cin >> N >> M;
	map<string, string>m;
	while (N--) {
		cin >> domain >> pw;
		m.insert({ domain,pw });
	}
	while (M--) {
		cin >> domain;
		cout << m.find(domain)->second << '\n';
	}
}