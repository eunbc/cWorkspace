#include <bits/stdc++.h>
using namespace std;

//올바른 괄호 
//https://school.programmers.co.kr/learn/courses/30/lessons/12909

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')') {
            if(!st.empty()) st.pop();
            else {
                answer = false;
                break;
            }
        }
    }
    if(!st.empty()) answer = false;
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "(()(";
    cout << solution(s);
}