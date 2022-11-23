#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll a,b,c;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    ll val = 1;
    while(b--) {
        val = val * a;
    }
    cout << val % c;
}