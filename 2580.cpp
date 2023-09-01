#include<iostream>
using namespace std;
int sudoku[10][10];
int garo[10][10];
int sero[10][10];
int nemo[10][10];
int main() {
	int cnt{ 0 };
	for (int i{ 1 }; i < 10; i++) {
		for (int j{ 1 }; j < 10; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				cnt++;
			}
		}
	}
	while (cnt > 0) {
		for (int i{ 1 }; i < 10; i++) {
			for (int j{ 1 }; j < 10; j++) {
				if (sudoku[i][j] == 0) {
					int ans{ 0 };
					bool isExist[10] = { false };
					for (int k{ 1 }; k < 10; k++) {
						if (j != k) {
							isExist[sudoku[i][k]] = true;
						}
					}
					for (int k{ 1 }; k < 10; k++) {
						if (i != k) {
							isExist[sudoku[k][j]] = true;
						}
					}
					for (int k{ (i - 1) / 3 * 3 + 1 }; k < (i - 1) / 3 * 3 + 4; k++) {
						for (int l{ (j - 1) / 3 * 3 + 1 }; l < (j - 1) / 3 * 3 + 4; l++) {
							if ((i != k || j != l)) {
								isExist[sudoku[k][l]] = true;
							}
						}
					}
					for (int k{ 1 }; k < 10; k++) {
						if (isExist[k] == false) {
							ans = k;
							break;
						}
					}
					sudoku[i][j] = ans;
					cnt--;

				}
			}
		}
	}
	for (int i{ 1 }; i < 10; i++) {
		for (int j{ 1 }; j < 10; j++) {
			cout << sudoku[i][j] << ' ';
		}
		cout << '\n';
	}
}