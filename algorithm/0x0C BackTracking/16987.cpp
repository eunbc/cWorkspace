#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int s[10],w[10];

void func(int k) {
    if(k==n) return;
    
    for(int i=k+1; i<n; i++) {
        
        func(k+1);
        
    }

    
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s[i];
        cin >> w[i];
    }
    func(0);
    cout << cnt;
}