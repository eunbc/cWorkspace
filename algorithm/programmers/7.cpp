#include <bits/stdc++.h>
using namespace std;

//숫자의 표현
//https://school.programmers.co.kr/learn/courses/30/lessons/12924

int solution(int n) {
    int answer = 0;
    //i는 start number
    for(int i=1; i<=n; i++) {
        int sum = 0;
        for(int j=i; j<=n; j++) {
            sum += j;
            if(sum == n) {answer++; break;}
            else if(sum > n) break;
        }
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 15;
    cout << solution(n);
}