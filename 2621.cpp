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
	char c;
	int n;
	int color[4] = { 0, };
	bool C{ false };
	bool pair1{ false };
	bool pair2{ false };
	bool triple{ false };
	bool four{ false };
	bool five{ false };
	int tmp{ 0 }, tmp1{ 0 };
	int cnt{ 1 };
	bool straight{ false };
	bool flush{ false };
	vector<int>num;
	for (int i{ 0 }; i < 5; i++) {
		cin >> c >> n;
		num.push_back(n);
		if (c == 'R') {
			color[0]++;
			if (color[0] == 5) {
				C = true;
			}
		}
		else if (c == 'G') {
			color[1]++;
			if (color[1] == 5) {
				C = true;
			}
		}
		else if (c == 'B') {
			color[2]++;
			if (color[2] == 5) {
				C = true;
			}
		}
		else if (c == 'Y') {
			color[3]++;
			if (color[3] == 5) {
				C = true;
			}
		}	
	}
	sort(num.begin(), num.end());
	if (num[4] - num[0] == 4 && num[1] != num[2]&& num[2] != num[3] &&num[3] != num[4]) {
		straight = true;
	}
	for (int i{ 1 }; i < 5; i++) {
		if (num[i-1] == num[i]) {
			cnt++;
		}
		if (num[i - 1] != num[i] || i == 4) {
			if (cnt == 2) {
				if (pair1) {
					pair2 = true;
					tmp1 = num[i - 1];
				}
				else {
					pair1 = true;
					if (triple) {
						tmp1 = num[i - 1];
					}
					else {
						tmp = num[i - 1];
					}
				}
			}
			else if (cnt == 3) {
				triple = true;
				if (pair1) {
					tmp1 = num[i - 1];
					int a{ tmp1 };
					tmp1 = tmp;
					tmp = a;
				}
				else {
					tmp = num[i - 1];
				}
				
			}
			else if (cnt == 4) {
				four = true;
				tmp = num[i - 1];
			}
			else if (cnt == 5) {
				five = true;
				tmp = num[i - 1];
			}
			cnt = 1;
		}
		
	}
	if (C&&straight) {
		cout << num[4] + 900;
	}
	else if (four) {
		cout << tmp + 800;
	}
	else if (triple&&pair1) {
		cout << tmp * 10 + tmp1 + 700;
	}
	else if (C) {
		cout << num[4] + 600;
	}
	else if (straight) {
		cout << num[4] + 500;
	}
	else if (triple) {
		cout << tmp + 400;
	}
	else if (pair1&&pair2) {
		cout << tmp1 * 10 + tmp + 300;
	}
	else if (pair1){
		cout << tmp + 200;
	}
	else {
		cout << 100 + num[4];
	}

}