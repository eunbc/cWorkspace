#include <bits/stdc++.h>
using namespace std;

int n;
int p[1005];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> p[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            p[i] = max(p[i-j]+p[j],p[i]);
        }
    }

    cout << p[n];

}