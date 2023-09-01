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
//토마토가 들어있지 않은 칸의 갯수
int noTomato;
//익은 토마토가 들어있는 칸의 갯수
int tomato;
//경과된 시간
int day;
//불가능여부 변수
bool impossible;
//활용할 큐
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
		//상 -- 빈칸이고 이동할
		if (cursor.Y < N - 1 && matrix[cursor.Y + 1][cursor.X] == 0) {
			q.push({ cursor.Y + 1, cursor.X });
			matrix[cursor.Y + 1][cursor.X] = 1;
			tomato++;
			flag = true;
		}
		//하
		if (cursor.Y > 0 && matrix[cursor.Y - 1][cursor.X] == 0) {
			q.push({ cursor.Y - 1, cursor.X });
			matrix[cursor.Y - 1][cursor.X] = 1;
			tomato++;
			flag = true;
		}
		//좌
		if (cursor.X > 0 && matrix[cursor.Y][cursor.X - 1] == 0) {
			q.push({ cursor.Y, cursor.X - 1 });
			matrix[cursor.Y][cursor.X - 1] = 1;
			tomato++;
			flag = true;
		}
		//우
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
			//초기상태에서 익은 토마토 위치 큐에 삽입, 갯수 카운트
			if (matrix[i][j] == 1) {
				q.push({ i,j });
				tomato++;
			}
			//토마토가 없는 곳 카운트
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
		//전체 칸 수와 토마토가 없는 칸 + 익은 토마토가 있는 칸이 같으면 순회 끝.. 
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