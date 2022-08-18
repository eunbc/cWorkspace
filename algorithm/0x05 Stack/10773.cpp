#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    stack<int> s;
    while(k--) {
        int n;
        cin >> n;
        if(n==0) s.pop();
        else s.push(n);
    }
    int sum = 0;
    int size = s.size();
    while(size--) {
        sum += s.top();
        s.pop();
    }
    cout << sum; 
}