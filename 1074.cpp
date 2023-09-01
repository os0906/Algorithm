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
int cnt;
void visit(vector<vector<int>>& v, int N, int r, int c, int start) {
	if (N == 0) {
		return;
	}
	v[r][c] = start;
	v[r + pow(2, N - 1) - 1][c + pow(2, N) - 1] = v[r][c] + pow(2, 2 * N - 1) - 1;
	v[r + pow(2, N - 1)][c] = v[r + pow(2, N - 1) - 1][c + pow(2, N) - 1] + 1;
	v[r + pow(2, N) - 1][c + pow(2, N) - 1] = v[r + pow(2, N - 1)][c] + pow(2, 2 * N - 1) - 1;
	visit(v, N - 1, r, c, start);
	visit(v, N - 1, r, c + pow(2, N - 1), start + pow(2, pow(2, N - 1)));
	visit(v, N - 1, r + pow(2, N - 1), c, start + 2 * pow(2, pow(2, N - 1)));
	visit(v, N - 1, r + pow(2, N - 1), c + pow(2, N - 1), start + 3 * pow(2, pow(2, N - 1)));
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, r, c;
	cin >> N >> r >> c;
	vector<vector<int>>v(pow(2, N) + 1, vector<int>(pow(2, N) + 1, 0));
	visit(v, N, 1, 1, 0);
	cout << v[r + 1][c + 1];
}