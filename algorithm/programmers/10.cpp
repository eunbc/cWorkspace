#include <bits/stdc++.h>
using namespace std;

//짝지어 제거하기
//https://school.programmers.co.kr/learn/courses/30/lessons/12973

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    for(int i=0; i<s.size(); i++) {
        if(st.empty()) st.push(s[i]);
        else if(st.top()!=s[i]) st.push(s[i]);
        else if(st.top()==s[i]) st.pop();
    }
    if(st.empty()) answer = 1;
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "cdcd";
    cout << solution(s);
}