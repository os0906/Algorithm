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
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, tmp, sum{ 0 }, s{ 0 };
	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j <= i; j++) {
			s += v[j];
		}
		sum += s;
		s = 0;
	}
	cout << sum;
}