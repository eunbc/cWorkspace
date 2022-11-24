#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n) {
    if(n==1) {
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a,6-a-b,n-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b,b,n-1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,na;
    cin >> n;
    na = n;
    int val = 1;
    while(na--) {
        val *= 2;
    }
    cout << val-1 << '\n';
    func(1,3,n);
}