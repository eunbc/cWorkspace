#include <bits/stdc++.h>
using namespace std;

char arr[2187][2187];

void func(int n,int x,int y) {
    if(n==1) return;
    for(int i=x+n/3; i< x+2*(n/3); i++) {
        for(int j=y+n/3; j<y+2*(n/3); j++) {
            arr[i][j] = ' ';
        }
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            func(n/3, x+i*(n/3), y+j*(n/3));
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = '*';
        }
    }
    func(n,0,0);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }   
}