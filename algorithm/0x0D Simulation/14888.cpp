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

    for(int i=0; i<n; i++) {
        cin >> num[i];
    }

    for(int i=0, idx = 1; i<4; i++) {
        int x;
        cin >> x;
        while (x--) {
            ops[idx++] = i;
        }
    }

    do {
        int res = 0;
        for(int i=0; i<n; i++) {
            if(ops[i]==0) res += num[i];
            else if(ops[i]==1) res -= num[i];
            else if(ops[i]==2) res *= num[i];
            else res /= num[i];
        }
        mx = max(mx, res);
        mn = min(mn, res);
    }while(next_permutation(ops+1,ops+n));

    cout << mx << '\n' << mn;
    
}