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

int arr[42];
int tmp;
int ans;
int main() {
	for (int i{ 0 }; i < 10; i++) {
		cin >> tmp;
		arr[tmp % 42]++;
	}
	for (int i{ 0 }; i < 42; i++) {
		if (arr[i] != 0) {
			ans++;
		}
	}
	cout << ans;
}