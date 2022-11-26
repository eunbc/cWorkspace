#include <bits/stdc++.h>
using namespace std;

int arr[128][128];
int white, blue;

void result(int a) {
    if(a==0) white++;
    else if(a==1) blue++;
}

bool check(int n, int x, int y) {
    for(int i=x; i<n+x; i++) {
        for(int j=y; j<n+y; j++) {
            if(arr[x][y]!=arr[i][j]) return false;
        }
    }
    return true;
}

void func(int n, int x, int y) {
    if(n==1) {
        result(arr[x][y]);
        return;
    }
    bool use = check(n,x,y);
    if(use) {
        result(arr[x][y]);
    } else {
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                func(n/2, x+i*(n/2), y+j*(n/2));
            }
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
            cin >> arr[i][j];
        }
    }
    func(n,0,0);
    cout << white << '\n' << blue;
}