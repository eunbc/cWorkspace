#include <bits/stdc++.h>
using namespace std;

int k;
int s[50], print[6];

void func(int cur, int v) {
    if(cur==6) {
        for(int i=0; i<6; i++) {
            cout << print[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 0;
    if(cur!=0) st = v+1; 
    for(int i=st; i<k; i++) {
        print[cur] = s[i];
        func(cur+1, i);
    }
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin >> k;
        if(k==0) break;
        for(int i=0; i<k; i++) {
            cin >> s[i];
        }
        sort(s, s+k);
        func(0,0);
        cout << '\n';
    }
}