#include <bits/stdc++.h>
using namespace std;

int n,m,k,r,c;
int note[40][40];
int sticker[10][10];

bool ispastable(int x, int y, int r, int c) {
    
}
int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> sticker[i][j];
            }
        }          
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(ispastable(i,j,r,c)) break;
                // else rotate()
            }
        }  
    }
    
    
}