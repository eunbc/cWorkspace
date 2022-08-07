#include <bits/stdc++.h>
using namespace std;

bool a[1000001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n=0,x=0,res=0;
    cin >> n;
    int b[n];
    for(int i=0;i<n;i++) {
        cin >> b[i]; 
        a[b[i]] = 1; 
    }

    cin >> x;
    for(int i=0;i<n; i++) {
        if(a[x-b[i]]==1) res++; 
    }

    cout << res/2;
 
}