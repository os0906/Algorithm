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
int N, M;
vector<int>s{ 1,2,3,4,5,6,7,8 };
vector<vector<int>>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	vector<int>temp(N);
	for (int i{ 0 }; i < M; i++) {
		temp[i] = 1;
	}
	int cnt{ 0 };
	do {
		vector<int>tmp;
		for (int i{ 0 }; i < N; i++) {
			if (temp[i] == true) {
				tmp.push_back(s[i]);
			}
		}
		do {
			vector<int>ttmp;
			for (int i{ 0 }; i <tmp.size(); i++) {
				ttmp.push_back(tmp[i]);
			}
			v.push_back(ttmp);
		} while (next_permutation(tmp.begin(), tmp.end()));
	} while (prev_permutation(temp.begin(),temp.end()));

	sort(v.begin(), v.end());
	for (auto i : v) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}