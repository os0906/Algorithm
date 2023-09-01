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
	int N, M, B, tmp;
	vector<int>land;
	cin >> N >> M >> B;
	int Max = -1;
	int Min = 501;
	int highLand{ 0 };
	int lowLand{ 0 };
	int upRequire{ 0 };
	int downRequire{ 0 };
	int digTime{ 0 };
	for (int i{ 0 }; i < N * M; i++) {
		cin >> tmp;
		Max = max(Max, tmp);
		Min = min(Min, tmp);
		land.push_back(tmp);
	}
	for (int i{ 0 }; i < N * M; i++) {
		if (Max == land[i]) {
			highLand++;
		}
		else {
			lowLand++;
		}
	}
	
	for (int i{ 0 }; i < N * M; i++) {
		upRequire += Max - land[i];
	}//11
	for (int i{ 0 }; i < N * M; i++) {
		downRequire += 2 * (land[i] - Min);
	}//2
	if (upRequire < downRequire) {
		if (B >= upRequire) {
			
		}
	}
	else {

	}
}