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
	int N, M;
	long long int tmp1, tmp2;
	cin >> N >> M;
	long long int sum{ 0 };
	priority_queue<long long int,vector<long long int>, greater<long long int>>pq;
	while (N--) {
		cin >> tmp1;
		pq.push(tmp1);
	}
	while (M--) {
		tmp1 = pq.top();
		pq.pop();
		tmp2 = pq.top();
		pq.pop();
		pq.push(tmp1 + tmp2);
		pq.push(tmp1 + tmp2);
	}
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}