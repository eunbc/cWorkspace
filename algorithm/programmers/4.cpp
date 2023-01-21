#include <bits/stdc++.h>
using namespace std;

//최솟값 만들기
//https://school.programmers.co.kr/learn/courses/30/lessons/12941?language=cpp

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0; i<A.size(); i++) {
        answer += (A[i] * B[A.size()-1-i]); 
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a = {1,4,2};
    vector<int> b = {5,4,4}; 
    cout << solution(a,b);
}