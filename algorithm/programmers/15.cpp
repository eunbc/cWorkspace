#include <bits/stdc++.h>
using namespace std;

//예상 대진표
//https://school.programmers.co.kr/learn/courses/30/lessons/12985

int answer = 1;

int solution(int n, int a, int b)
{
    a = (a+1)/2;
    b = (b+1)/2;
    if(a==b) return answer;
    answer++;
    solution(n/2, a, b);
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 8, a = 4, b = 7;
    cout << solution(n,a,b);
}