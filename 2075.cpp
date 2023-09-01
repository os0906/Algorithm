#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int arr[2550001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i{ 0 }; i < N*N; i++) {      
        int tmp;
        cin >> tmp;
        pq.push(tmp);
        while (pq.size() > N){
            pq.pop();
        }
    }
    cout << pq.top();
}