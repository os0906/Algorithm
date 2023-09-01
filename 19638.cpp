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

	//»ðÀÔ ÃÑ < NlogN
	while (N--) {
		cin >> tmp;
		pq.push(tmp);
	}
	int cnt{ 0 };

	//¸ÁÄ¡·Î ¶§¸®´Â ½ÃÇà T¹ø ¹Ýº¹
	while (T--) {
		//»ó¼öÅ¸ÀÓ
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
	//T¹ø ¶§¸° ÈÄ pq Á¶»ç
	if (H <= pq.top()) {//­C
		cout << "NO" << '\n' << pq.top();
	}
	else {
		cout << "YES" << '\n' << cnt;
	}
}