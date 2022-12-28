#include <bits/stdc++.h>
using namespace std;

int n;
int num[12];
int ops[12];
int mx = -0x7f7f7f7f;
int mn = 0x7f7f7f7f;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) cin >> num[i];
    for(int op=0, idx = 1; op<4; op++) {
        int x; cin >> x;
        while(x--) ops[idx++] = op;
    }

    for(int i=0; i<12; i++) {
        cout << ops[i];
    }
    // cout << mx << '\n' << mn << '\n';
}