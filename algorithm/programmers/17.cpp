#include <bits/stdc++.h>
using namespace std;

//멀리 뛰기
//https://school.programmers.co.kr/learn/courses/30/lessons/12914

#include <string>
#include <vector>

using namespace std;
long long arr[2005];

long long solution(int n) {
    long long answer = 0;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=n; i++) {
        arr[i] = arr[i-1]%1234567 + arr[i-2]%1234567; 
    }
    answer = arr[n] % 1234567;
    // a[0]  === 0
    // a[1] 1 === 1
    // a[2] 1 1 / 2 === 2
    // a[3] 1 1 1 / 2 1 / 1 2 === 3
    // a[4] 1 1 1 1 / 2 1 1 / 1 2 1 / 1 1 2 / 2 2 === 5

    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 3;
    cout << solution(n);
}