#include <bits/stdc++.h>
using namespace std;

int n;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int a=0,b=0;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        cout << a+b << '\n';
    } 
}