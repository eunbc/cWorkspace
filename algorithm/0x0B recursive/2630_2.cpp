#include <bits/stdc++.h>
using namespace std;

int white;
int blue;
int arr[128][128];

void sum(int xy) {
    if(xy==0) white++;
    else blue++;
}

bool check(int n, int x, int y) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(arr[x][y]!=arr[i][j]) {
                return false;
            } 
        }
    }
    return true;
}

void func(int n, int x, int y) {
    if(n==1) {
        sum(arr[x][y]);
        return; 
    }   

    bool res = check(n,x,y);
    if(res) {
        sum(arr[x][y]);
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

