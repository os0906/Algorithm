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
	queue<int> trucks;
	int N, W, L, tmp;
	cin >> N >> W >> L;
	for (int i{ 0 }; i < N; i++) {
		cin >> tmp;
		trucks.push(tmp);
	}
	deque<pair<int,int>> bridge;
	int weightOnBridge{ 0 };
	int ans{ 0 };
	while (!(bridge.empty() && trucks.empty())) {
		for (int i = 0; i < bridge.size(); i++) {
			bridge[i].second -= 1;
		}	
		if (!bridge.empty() && bridge.front().second == 0) {
			weightOnBridge -= bridge.front().first;
			bridge.pop_front();
		}
		if (!trucks.empty() && weightOnBridge + trucks.front() <= L && bridge.size() < W) {
			bridge.push_back({ trucks.front(),W });
			weightOnBridge += trucks.front();
			trucks.pop();
		}
		ans++;
	}
	cout << ans;
}