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
//비용 행렬
int arr[11][11];
//순열 배열
int city[11];
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	//N^2이지만 N<=10이므로 상관 없음
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			cin >> arr[i][j];
			// arr[i][j] = i에서 j로 가는 비용
		}
	}


	// N (<=10) 순열함수 돌릴 배열에 도시 번호 붙여주기
	for (int i{ 1 }; i <= N; i++) {
		city[i] = i;
	}

	//최소비용 최대한 크게 잡아주기
	int mincost = 2E9;


	do {
		int cost = 0;
		bool visitAll = true;

		// N (<=10)
		for (int i = 1; i <= N - 1; i++) {
			//city[i]에서 city[i+1]로 갈 수 있다면(경로가 존재한다면)
			if (arr[city[i]][city[i + 1]] > 0) {
				//비용에 추가
				cost += arr[city[i]][city[i + 1]];
			}
			else {
				visitAll = false; // 경로가 없어서 실패.
				break;
			}
		}

		// 마지막 N번 도시에서 1번 도시로 (시작점으로) 오는 경로가 있는 경우 비용을 합산. 
		if (arr[city[N]][city[1]] > 0) {
			cost += arr[city[N]][city[1]];
		}
		else {
			visitAll = false; // 모든 도시 방문 실패.  
		}

		if (visitAll) {
			mincost = min(cost, mincost);
		}
	} 
	while (next_permutation(city, city + N));
	//while문이 N!번만큼 돌아감. 최대 3'628'800번 -> 상관 X
	cout << mincost;
}