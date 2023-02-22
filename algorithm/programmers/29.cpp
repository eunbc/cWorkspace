#include <bits/stdc++.h>
using namespace std;

//최고의 집합
//https://school.programmers.co.kr/learn/courses/30/lessons/12938

vector<int> solution(int n, int s) {
    vector<int> answer;
    while(n>0) {
        answer.push_back(s/n);
        s -= (s/n);
        n--;
    }
    if(answer[0]==0) return {-1};
    return answer;
}


int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 2, s = 1;
    vector<int> res = solution(n,s);
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << '\n';
    }
}