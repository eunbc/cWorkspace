#include <bits/stdc++.h>
using namespace std;

bool func(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='[' || s[i]=='{' || s[i]=='(') st.push(s[i]);
        
    }    


}

int solution(string s) {
    int answer = -1;
    stack<char> st;

    //회전
    int len = s.length();
    for(int i=0; i<len; i++) {
        string first = s.substr(0,1);
        string sub = s.substr(1,len-1);
        s = sub + first;
        answer += func(s);        
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "[](){}";
    cout << solution(s);   
}