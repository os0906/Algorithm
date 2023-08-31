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
bool compare(vector<int> v1, vector<int>v2) {
	if (v1[1] == v2[1]) {
		if (v1[2] == v2[2]) {
			return v1[3] > v2[3];
		}
		return v1[2] > v2[2];
	}
	return v1[1] > v2[1];

	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> v;
	int N, K;
	int k;
	cin >> N >> K;
	for (int i{ 0 }; i < N; i++) {
		vector<int>vtmp;
		v.push_back(vtmp);
		for (int j{ 0 }; j < 4; j++) {
			cin >> k;
			v[i].push_back(k);
		}
	}
	sort(v.begin(), v.end(), compare);
	vector<int> ans;
	int prev[3] = { -1,-1,-1 };
	for (int i{ 0 }; i < N; i++) {
		if (prev[0] == v[i][1] && prev[1] == v[i][2] && prev[2] == v[i][3]) {
			ans.push_back(ans[ans.size() - 1]);
		}
		else {
			ans.push_back(i + 1);
		}
		prev[0] = v[i][1];
		prev[1] = v[i][2];
		prev[2] = v[i][3];
	}
	for (int i{ 0 }; i < N; i++) {
		if (K == v[i][0]) {
			k = i;
			break;
		}
	}
	cout << ans[k];
}