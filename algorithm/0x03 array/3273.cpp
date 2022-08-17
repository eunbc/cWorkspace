#include <bits/stdc++.h>
using namespace std;

bool b[1000001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n=0,x=0,res=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i]; 
        b[a[i]] = 1; 
    }

    cin >> x;

    for(int i=0; i<n; i++) {
        if(x-a[i] > 0 && b[x-a[i]]==1) res++;
    }
    
    cout << res/2;
 
}