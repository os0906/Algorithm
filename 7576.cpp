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
#define Y first
#define X second
using namespace std;

int matrix[1001][1001];
int N, M;
//�丶�䰡 ������� ���� ĭ�� ����
int noTomato;
//���� �丶�䰡 ����ִ� ĭ�� ����
int tomato;
//����� �ð�
int day;
//�Ұ��ɿ��� ����
bool impossible;
//Ȱ���� ť
queue<pair<int, int>> q;

void bfs() {
	bool flag = false;
	pair<int, int> last;
	if (!q.empty()) {
		last = q.back();
	}
	while (!q.empty()) {
		pair<int, int> cursor = q.front();
		q.pop();
		//�� -- ��ĭ�̰� �̵���
		if (cursor.Y < N - 1 && matrix[cursor.Y + 1][cursor.X] == 0) {
			q.push({ cursor.Y + 1, cursor.X });
			matrix[cursor.Y + 1][cursor.X] = 1;
			tomato++;
			flag = true;
		}
		//��
		if (cursor.Y > 0 && matrix[cursor.Y - 1][cursor.X] == 0) {
			q.push({ cursor.Y - 1, cursor.X });
			matrix[cursor.Y - 1][cursor.X] = 1;
			tomato++;
			flag = true;
		}
		//��
		if (cursor.X > 0 && matrix[cursor.Y][cursor.X - 1] == 0) {
			q.push({ cursor.Y, cursor.X - 1 });
			matrix[cursor.Y][cursor.X - 1] = 1;
			tomato++;
			flag = true;
		}
		//��
		if (cursor.X < M - 1 && matrix[cursor.Y][cursor.X + 1] == 0) {
			q.push({ cursor.Y, cursor.X + 1 });
			matrix[cursor.Y][cursor.X + 1] = 1;
			tomato++;
			flag = true;
		}
		if (cursor == last) {
			break;
		}
	}
	if (flag == false) {
		impossible = true;
		return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			cin >> matrix[i][j];
			//�ʱ���¿��� ���� �丶�� ��ġ ť�� ����, ���� ī��Ʈ
			if (matrix[i][j] == 1) {
				q.push({ i,j });
				tomato++;
			}
			//�丶�䰡 ���� �� ī��Ʈ
			else if (matrix[i][j] == -1) {
				noTomato++;
			}
		}
	}

	while (1) {
		if (impossible == true) {
			cout << -1;
			return 0;
		}
		//��ü ĭ ���� �丶�䰡 ���� ĭ + ���� �丶�䰡 �ִ� ĭ�� ������ ��ȸ ��.. 
		if (N * M - noTomato == tomato) {
			cout << day;
			return 0;
		}
		bfs();
		
		cout << '\n';
		for (int i{ 0 }; i < N; i++) {
			for (int j{ 0 }; j < M; j++) {
				cout << matrix[i][j] << ' ';
			}
			cout << '\n';
		}
		
		day++;
	}
}