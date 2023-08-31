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
	cin >> N >> M;
	map<string,bool> m;
	string tmp;
	int cnt{ 0 };
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		m.insert({ tmp,false });
	}
	for (int i{ 0 }; i < M; i++) {
		cin >> tmp;
		if (m.find(tmp) != m.end()) {
			m[tmp] = true;
			cnt++;
		}
	}
	cout << cnt<<endl;
	for (auto iter: m) {
		if(iter.second==true)
		cout << iter.first << endl;
	}
}