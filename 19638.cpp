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


	priority_queue<int> pq;
	int N, H, T, tmp;
	cin >> N >> H >> T;

	//삽입 총 < NlogN
	while (N--) {
		cin >> tmp;
		pq.push(tmp);
	}
	int cnt{ 0 };

	//망치로 때리는 시행 T번 반복
	while (T--) {
		//상수타임
		if (H > pq.top()) {
			cout << "YES" << '\n' << cnt;
			return 0;
		}
		else {
			
			tmp = pq.top();
			//log N
			pq.pop();
			//log N
			if (tmp == 1) {
				pq.push(1);
			}			else {
				pq.push(tmp / 2);
			}
			cnt++;
		}
	}
	//T번 때린 후 pq 조사
	if (H <= pq.top()) {//쵣
		cout << "NO" << '\n' << pq.top();
	}
	else {
		cout << "YES" << '\n' << cnt;
	}
}