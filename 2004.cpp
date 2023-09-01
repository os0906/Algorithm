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
int power(int n, int p) {
    int pow = 0;

    while (n >= p) {
        pow += n / p;
        n /= p;
    }

    return pow;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    cout << min(power(N, 2) - power(M, 2) - power(N - M, 2), power(N, 5) - power(M, 5) - power(N - M, 5));
}