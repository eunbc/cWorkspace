#include <bits/stdc++.h>
using namespace std;

//예상 대진표
//https://school.programmers.co.kr/learn/courses/30/lessons/12985

int solution(int n, int a, int b)
{
    a--;
    b--;
    int answer = 0;
    while(a!=b) {
        a /= 2;
        b /= 2;
        answer++;
        cout << "a,b,answer = " << a << ' ' << b << ' ' << answer << '\n';
    }
    return answer-1;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 8, a = 4, b = 7;
    cout << solution(n,a,b);
}