#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> q;

    while(n--) {
        string a;
        cin >> a;
        if(a=="push") {
            int x;
            cin >> x;
            q.push(x);
        } else if(a=="pop") {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if(a=="size") {
            cout << q.size() << '\n';
        } else if(a=="empty") {
            cout << q.empty() << '\n';
        } else if(a=="front") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        } else if(a=="back") {
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
}