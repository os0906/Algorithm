#include<iostream>
#include<deque>
using namespace std;

int main() {

	int N, tmp;
	cin >> N;
	deque<pair<int,int>> d;

	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		d.push_back({ tmp, i + 1 });
	}

	while (1) {
		int move = d.front().first;
		int idx = d.front().second;
		cout << idx << ' ';
		d.pop_front();
		if (d.empty()) {
			return 0;
		}
		if (move > 0) {
			for (int i{ 0 }; i < move - 1; i++) {
				pair<int,int> tmp = d.front();
				d.pop_front();
				d.push_back(tmp);
			}
		}
		else {
			for (int i{ 0 }; i < abs(move); i++) {
				pair<int, int> tmp = d.back();
				d.pop_back();
				d.push_front(tmp);
			}
		}
	}
}