#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> st;
    while(n--) {
        string s;
        cin >> s;
        if(s=="push") {
            int x;
            cin >> x;
            st.push(x);
        } else if(s=="pop") {
            if(st.empty()) cout << -1 << '\n';
            else {
                cout << st.front() << '\n';
                st.pop();
            }
        } else if(s=="size") {
            cout << st.size() << '\n';
        } else if(s=="empty") {
            cout << st.empty() << '\n';
        } else if(s=="front") {
            if(st.empty()) cout << -1 << '\n';
            else cout << st.front() << '\n';
        } else if(s=="back") {
            if(st.empty()) cout << -1 << '\n';
            else cout << st.back() << '\n';
        }
    }
}