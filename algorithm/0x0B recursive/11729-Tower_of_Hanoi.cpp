/*
    n-1개의 원판을 기둥1에서 기둥2로 옮긴다.
    n번 원판을 기둥1에서 기둥3으로 옮긴다.
    n-1개의 원판을 기둥2에서 기둥3으로 옮긴다.
    -> 원판이 n-1개일 때 옮길 수 있으면 원판이 n개일 때에도 옮길 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

void func(int a,int b, int n) {
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
    int k;
    cin >> k;
    cout << (1<<k) - 1 << '\n';
    func(1,3,k);
}