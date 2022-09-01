#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int answer = 0;
    while (n--) {
        string s;
        cin >> s;
        stack<char> st;
        bool isValid = true;
        for(auto c : s) {
            if(st.empty() || st.top()!= c) {
                st.push(c);
            }
            else {
                st.pop();
            }
        }
        if(!st.empty()) isValid = false;
        if(isValid) answer++;
    }
    
    cout << answer;
        
}