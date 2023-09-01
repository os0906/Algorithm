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
	int N;
	int ans{ 0 };
	string str;
	set<string>nickname;
	cin >> N;
	while (N--) {
		cin >> str;
		if (str != "ENTER") {
			if (nickname.find(str) == nickname.end()) {
				nickname.insert(str);
				ans++;
			}
		}
		else {
			nickname.clear();
		}
	}
	cout << ans;
}