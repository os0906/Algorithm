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
int N, tmp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue<int>pq;
	cin >> N;
	while (N--) {
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top()<<'\n';
				pq.pop();
			}
		}
		else {
			pq.push(tmp);
		}
	}
}