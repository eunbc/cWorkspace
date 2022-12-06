#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024*3;
char arr[MAX][2*MAX-1];

void func(int n, int x,int y) {
    if(n==3) {
        
    }
    int nx = n/2;
    // func(nx, , 0);
    func(nx, 0, 0);
    func(nx, 0, 0);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n;
    func(n,0,n-1);

    for(int i=0; i<n; i++) {
        for(int j=0; j<2*n-1; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}
