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
	string str;
	string bomb;
	stack<char>s;
	vector<bool>flags;
	vector<int>bombIdxs;
	bool flag{ false };
	int bombIdx{ 0 };
	cin >> str >> bomb;
	for (int i{ 0 }; i < str.length(); i++) {
		s.push(str[i]);
		if (s.top() == bomb[bombIdxs.back()]) {
			if (bombIdx == bomb.size()) {
				for (int j{ 0 }; j < bomb.length(); j++) {
					s.pop();
				}
				flag = false;
				bombIdx = 0;
			}
			flag = true;
			bombIdx++;

		}
		else {
			flag = false;
		}
	}

}