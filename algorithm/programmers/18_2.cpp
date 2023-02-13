#include <bits/stdc++.h>
using namespace std;

//H-Index
//https://school.programmers.co.kr/learn/courses/30/lessons/42747

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(),greater<>());
    for(int i=1; i<=citations.size(); i++) {
        if(citations[i-1] >= i) answer = i;
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> citations = {3,0,6,1,5};
    cout << solution(citations);
}