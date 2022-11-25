#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int arr[2187][2187];

void result(int x) {
    if(x==-1) a = a + 1;
    else if(x==0) b = b + 1;
    else if(x==1) c = c + 1;
}

void func(int n, int x, int y) {
    if(n==1) {
        result(arr[x][y]);
        return;
    }
    
    bool use = true;
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(arr[x][y]!= arr[i][j]) {
                use = false;
                break;
            } 
        }
    }
    if(!use) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                func(n/3, i*(n/3) + x ,j*(n/3) + y);
            }
        }
    } else if(use) {
        result(arr[x][y]);
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
    func(n, 0, 0);
    cout << a << '\n' << b << '\n' << c;
}