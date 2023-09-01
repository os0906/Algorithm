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
vector<vector<int>>v;
vector<bool>isVisited(101, false);
int ans{ 0 };

void visit(int n) {
	isVisited[n] = true;
	for (int i{ 0 }; i < v[n].size(); i++) {
		if (isVisited[v[n][i]] == true) {
			continue;
		}
		else {
			isVisited[v[n][i]] = true;
			ans++;
			visit(v[n][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> t;
	v.push_back(t);
	int N, P, n1, n2;
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		vector<int>v1;
		v.push_back(v1);
	}
	cin >> P;
	
	for (int i{ 0 }; i < P; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	visit(1);
	cout << ans;
}