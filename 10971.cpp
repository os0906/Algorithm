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
//��� ���
int arr[11][11];
//���� �迭
int city[11];
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	//N^2������ N<=10�̹Ƿ� ��� ����
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			cin >> arr[i][j];
			// arr[i][j] = i���� j�� ���� ���
		}
	}


	// N (<=10) �����Լ� ���� �迭�� ���� ��ȣ �ٿ��ֱ�
	for (int i{ 1 }; i <= N; i++) {
		city[i] = i;
	}

	//�ּҺ�� �ִ��� ũ�� ����ֱ�
	int mincost = 2E9;


	do {
		int cost = 0;
		bool visitAll = true;

		// N (<=10)
		for (int i = 1; i <= N - 1; i++) {
			//city[i]���� city[i+1]�� �� �� �ִٸ�(��ΰ� �����Ѵٸ�)
			if (arr[city[i]][city[i + 1]] > 0) {
				//��뿡 �߰�
				cost += arr[city[i]][city[i + 1]];
			}
			else {
				visitAll = false; // ��ΰ� ��� ����.
				break;
			}
		}

		// ������ N�� ���ÿ��� 1�� ���÷� (����������) ���� ��ΰ� �ִ� ��� ����� �ջ�. 
		if (arr[city[N]][city[1]] > 0) {
			cost += arr[city[N]][city[1]];
		}
		else {
			visitAll = false; // ��� ���� �湮 ����.  
		}

		if (visitAll) {
			mincost = min(cost, mincost);
		}
	} 
	while (next_permutation(city, city + N));
	//while���� N!����ŭ ���ư�. �ִ� 3'628'800�� -> ��� X
	cout << mincost;
}