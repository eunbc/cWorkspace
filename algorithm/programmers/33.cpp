#include <bits/stdc++.h>
using namespace std;

int arr[60005];

int solution(int n) {
    int answer = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<60001; i++) {
        arr[i] = arr[i-1] % 1000000007 + arr[i-2] % 1000000007;
        arr[i] %= 1000000007;
    }
    answer = arr[n];
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 4;
    cout << solution(n);
}