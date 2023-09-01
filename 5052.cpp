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
<<<<<<< HEAD
struct cmp1 {
	bool operator()(string& a, string& b) {
		return a.length() > b.length();

	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	string str;
	while (T--) {
		int N;
		cin >> N;
		priority_queue<string,vector<string>,cmp>pq;
		while (N--) {
			cin >> str;
			pq.push(str);
		}
		while (!pq.empty()) {
			string tmp = pq.top();
			pq.pop();
			if (pq.empty()) {
				break;
			}
			if (pq.top().find(tmp) == string::npos) {
				continue;
			}
			else {
				cout << "NO" << '\n';
				break;
			}
		}
		if (pq.empty()) {
			cout << "YES" << '\n';
		}
	}
=======
int T, N;
string tmp;
//Trie

struct Trie {
	Trie* Node[10];
	bool end;
	Trie() {
		end = false;
		for (int i = 0; i < 10; i++) Node[i] = NULL;
	}
	void insert(const char* str) {
		if (*str == NULL) {
			this->end = true;
			return;
		}
		int cur = *str - '0';
		if (Node[cur]==NULL) {
			Node[cur] = new Trie;
		} 
		Node[cur]->insert(str + 1);
	}
	bool find(const char* str) {
		if (*str == NULL) {
			if (end) {
				return true;
			} 
			return false;
		}
		if (*str != NULL) {
			if (end) {
				return false;
			}
		}
		int cur = *str - '0';
		if (Node[cur]==NULL) return false;
		return Node[cur]->find(str + 1);
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N;
		bool flag = true;
		priority_queue<string, vector<string>, greater<>>pq;
		Trie* root = new Trie;
		while (N--) {
			cin >> tmp;
			pq.push(tmp);
			root->insert(tmp.c_str());
		}
		while (!pq.empty()) {
			if (root->find(pq.top().c_str()) == false) {
				flag = false;
				cout << "NO" << '\n';
				break;
			}
			else {
				pq.pop();
			}
		}
		if (flag) {
			cout << "YES" << '\n';
		}
		
	}

>>>>>>> ff3643f445500a4356dba7142f1b392199b4ac8b
}