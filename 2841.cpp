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
	int N, P;
	int string, fret;
	cin >> N >> P;
	vector<stack<int>>v(P + 1, stack<int>());
	int ans{ 0 };
	while (N--) {
		cin >> string >> fret;
		if (v[string].empty()) {
			ans++;
			v[string].push(fret);
		}
		else {
			if (fret > v[string].top()) {
				v[string].push(fret);
				ans++;
			}
			else if (fret == v[string].top()) {
				continue;
			}
			else if(fret < v[string].top()){
				while (fret < v[string].top()) {
					v[string].pop();
					ans++;
					if (v[string].empty()) {
						ans++;
						v[string].push(fret);
						break;
					}
					if (fret == v[string].top()) {
						break;
					}
					
				}
				if (fret > v[string].top()) {
					ans++;
					v[string].push(fret);
				}
			}
		}
	}
	cout << ans++;
}