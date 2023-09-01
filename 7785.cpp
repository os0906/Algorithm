#include<iostream>
#include<map>
using namespace std;

int main() {
	map<string, bool,greater<string>> m;
	int T;
	string name, isEnter;
	cin >> T;
	while (T--) {
		cin >> name >> isEnter;
		if (m.find(name) != m.end()) {
			if (isEnter == "enter") {
				m.find(name)->second = 1;
			}
			else {
				m.find(name)->second = 0;
			}
		}
		else {
			if (isEnter == "enter") {
				m.insert({ name,1 });
			}
			else {
				m.insert({ name,0 });
			}
		}
	}
	for (auto& i : m) {
		if (i.second == 1) {
			cout << i.first << '\n';
		}
	}
}