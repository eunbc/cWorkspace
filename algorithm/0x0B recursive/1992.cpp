#include <bits/stdc++.h>
using namespace std;

char arr[64][64];

bool check(int n, int x, int y) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(arr[x][y]!=arr[i][j]) return false;
        }
    }
    return true;
 }

void func(int n, int x, int y) {
    if(n==1) {
        cout << arr[x][y];
        return;        
    }    
    bool same = check(n,x,y);
    if(same) {
        cout << arr[x][y];
    } else {
        cout << '(';
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                func(n/2, x+i*(n/2), y+j*(n/2));
            }
        }
        cout << ')';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    func(n,0,0);
}