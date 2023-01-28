#include <bits/stdc++.h>
using namespace std;

int F[100005];

//피보나치 수 
//https://school.programmers.co.kr/learn/courses/30/lessons/12945

int solution(int n) {
    int answer = 0;
    F[0] = 0;
    F[1] = 1;
    for(int i=2; i<=n; i++) {
        F[i] = F[i-1]%1234567 + F[i-2]%1234567;
    }
    answer = F[n]%1234567;
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 3;
    cout << solution(n);
}