#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
	string answer = "";
	vector<string> v1;
	vector<int> v2;
	v2.push_back(-1);
	//공백의 인덱스들 
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			v2.push_back(i);
		}
	}
	v2.push_back(s.length());
	for (int i = 0; i < v2.size() - 1; i++) {
		v1.push_back(s.substr(v2[i] + 1, v2[i + 1] - v2[i] - 1));
	}

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].length();  j++) {
			if (j % 2 == 0) {
				v1[i][j] = toupper(v1[i][j]);
			}
			else {
				v1[i][j] = tolower(v1[i][j]);
			}

		}
	}

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}

	for (int i = 0; i < v1.size(); i++) {
		answer += v1[i];
		if (i < v1.size() - 1) {
			answer += ' ';
		}
	}
	return answer;
}
