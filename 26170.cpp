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
int r, c;
int arr[5][5];
bool flag{ false };
priority_queue<int, vector<int>, greater<>>pq;
void dfs(int x, int y, int count, int apple) {
	if (apple == 3) {
		flag = true;
		pq.push(count);
		return;
	}

	int tmp = arr[x][y];
	if (x > 0 && arr[x - 1][y] != -1) {
		arr[x][y] = -1;
		dfs(x - 1, y, count + 1, apple + arr[x - 1][y]);
		arr[x][y] = tmp;
	}

	if (x < 4 && arr[x + 1][y] != -1) {
		arr[x][y] = -1;
		dfs(x + 1, y, count + 1, apple + arr[x + 1][y]);
		arr[x][y] = tmp;
	}

	if (y > 0 && arr[x][y - 1] != -1) {
		arr[x][y] = -1;
		dfs(x, y - 1, count + 1, apple + arr[x][y - 1]);
		arr[x][y] = tmp;
	}
	if (y < 4 && arr[x][y + 1] != -1) {
		arr[x][y] = -1;
		dfs(x, y + 1, count + 1, apple + arr[x][y + 1]);
		arr[x][y] = tmp;
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i{ 0 }; i < 5; i++) {
		for (int j{ 0 }; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> r >> c;
	dfs(r, c, 0, 0);
	if (pq.empty()) {
		cout << -1;
	}
	else{
		cout << pq.top();
	}
	
}