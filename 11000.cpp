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
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, input1, input2;
	cin >> T;
	for (int i{ 0 }; i < T; i++){
		cin >> input1 >> input2;
		v.push_back({input1,input2});
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);

	// 필요한 강의실 탐색
	for (int i = 1; i < T; ++i) {
		// i 번째 수업의 종료 시간을 pq 에 삽입
		pq.push(v[i].second);
		// top 의 종료 시간보다 i 번째 수업이 늦게 시작한다면, 같은 강의실에서 진행 가능
		if (pq.top() <= v[i].first) {
			// 기존의 top 은 제거
			pq.pop();
		}
	}
	cout << pq.size();
}
