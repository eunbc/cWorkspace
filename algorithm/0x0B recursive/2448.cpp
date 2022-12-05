#include <bits/stdc++.h>
using namespace std;

char arr[6144][6144];

void func(int n, int x,int y) {
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            arr[i][j] = ' ';
        }
        for(int j=0; j<i+1; j++) {
            arr[i][j] = '*';
        }
        for(int j=0; j<i; j++) {
            arr[i][j] = '*';
        }
        cout << '\n';
    }
    func(n,0,0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<2*n-1; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }    
}
