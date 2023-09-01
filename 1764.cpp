#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <utility>
#include <map>
<<<<<<< HEAD
#include <set>
=======
>>>>>>> ff3643f445500a4356dba7142f1b392199b4ac8b
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
<<<<<<< HEAD
	string tmp;
	cin >> N >> M;
	set<string> s1;
	set<string> s2;
	while (N--) {
		cin >> tmp;
		s1.insert(tmp);
	}
	while (M--) {
		cin >> tmp;
		if (s1.find(tmp) != s1.end()) {
			s2.insert(tmp);
		}
	}
	cout << s2.size() << '\n';
	for (string i : s2) {
		cout << i << '\n';
=======
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
>>>>>>> ff3643f445500a4356dba7142f1b392199b4ac8b
	}
}