#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    stack<char> st;
    int answer = 0;

    for(int i=0;i < s.length();i++) {
        if(s[i]=='(') {
            st.push(s[i]);
        } else {
            if(s[i-1]=='(') {
                st.pop();
                answer += st.size();
            }
            else {
                st.pop();
                answer += 1;
            }
        }
    }

    cout << answer;
    

}