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
bool cmp (pair<int, int>& a, pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second < b.second; 
	}
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int, int>> v;
	int T, input1, input2;
	cin >> T;
	while (T--) {
		cin >> input1 >> input2;
		v.push_back({ input1,input2 });
	}
	sort(v.begin(), v.end(), cmp);
	int time{ v[0].second };
	int ans{ 1 };
	for (int i{ 1 }; i < v.size(); i++) {
		if (time <= v[i].first) {
			ans++;
			time = v[i].second;
		}
	}
	cout << ans;
}