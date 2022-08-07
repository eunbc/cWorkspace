#include <bits/stdc++.h>
using namespace std;

int a[21],b[20];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<21;i++) {
        a[i]=i;
        cin >> b[i-1];
    }

    for(int i=0; i<10; i++) {
        int x=0,y=0;
        x = b[i*2];
        y = b[2*i+1];
        reverse(a+x,a+y+1);
    }

    for(int i=1;i<21;i++) {
        cout << a[i] << ' ';
    }
    
}