#include <bits/stdc++.h>
using namespace std;

//n^2 배열 자르기
//https://school.programmers.co.kr/learn/courses/30/lessons/87390

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left; i<=right; i++) {          
        int a = i/n;
        int b = i%n;
        if(b <= a) answer.push_back(a+1);
        else answer.push_back(b+1);
    } 
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 4;
    long long left = 7;
    long long right = 14;
    vector<int> res = solution(n,left, right);   
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    } 
}