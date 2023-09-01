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

	// �ʿ��� ���ǽ� Ž��
	for (int i = 1; i < T; ++i) {
		// i ��° ������ ���� �ð��� pq �� ����
		pq.push(v[i].second);
		// top �� ���� �ð����� i ��° ������ �ʰ� �����Ѵٸ�, ���� ���ǽǿ��� ���� ����
		if (pq.top() <= v[i].first) {
			// ������ top �� ����
			pq.pop();
		}
	}
	cout << pq.size();
}
