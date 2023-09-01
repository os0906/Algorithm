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
	int n;
	
	while (cin >> n) {
		int i{ 1 };
		int k = 1;
		while (1) {
			if (i % n == 0) {
				cout << k << endl;
				break;
			}
			i = i * 10 + 1;
			i %= n;
			k++;
		}
	}
}

/*핵심은 int 자료형에 담기지 않을 정도로 큰 수를 다룰때 모듈러 연산을 사용하는 것
A % B = (A % B) % B임을 기억하자*/