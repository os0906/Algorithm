#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}
int main() {
	int T{ 0 };
	cin >> T;
	string s;
	map<string, int> m;
	vector<pair<string, int>>v;
	while (T--) {
		cin >> s;
		if (m.find(s) != m.end()) {
			m.find(s)->second++;
		}
		else {
			m.insert({ s,1 });
		}
	}
	for (auto& i : m) {
		v.push_back(i);
	}
	sort(v.begin(), v.end(),comp);
	cout << v[0].first;
}
