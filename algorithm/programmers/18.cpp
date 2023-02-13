#include <bits/stdc++.h>
using namespace std;

//H-Index
//https://school.programmers.co.kr/learn/courses/30/lessons/42747

int solution(vector<int> citations) {
    int answer = 0;
    for(int i=1; i<=citations.size(); i++) {
        int tmp = 0;
        for(int j=0; j<citations.size(); j++) {
            if(citations[j]>=i) tmp++;
        }
        if(tmp >= i) answer = i;
    }    
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> citations = {3,0,6,1,5};
    cout << solution(citations);
}