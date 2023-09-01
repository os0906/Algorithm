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
#include <sstream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
    string tmp, L;
	vector<queue<string>>v;
	cin >> N;
    getline(cin, tmp);
    for (int i{ 0 }; i < N; i++) {
        //tmp에 줄단위로 입력받아서 q에 쪼개서 push
        queue<string>q;
        getline(cin, tmp);
        stringstream ss(tmp);
        string buffer;
        while (ss >> buffer) {
            q.push(buffer);
        }
        v.push_back(q);
    }
    //L에 줄단위로 입력받아서 ansQ에 쪼개서 push
    getline(cin, L);
    queue<string>ansQ;
    stringstream ss(L);
    string buffer;
    while (ss >> buffer) {
        ansQ.push(buffer);
    }
    while (!ansQ.empty()) {
        bool flag = false;
        for (auto &i : v) {
            if (i.empty()) {}
            else if (i.front() == ansQ.front()) {
                i.pop();
                ansQ.pop();
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << "Impossible";
            return 0;
        }
    }
    for (auto& i : v) {
        if (!i.empty()) {
            cout << "Impossible";
            return 0;
        }
    }
    cout << "Possible";
}