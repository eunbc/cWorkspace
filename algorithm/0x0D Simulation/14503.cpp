#include <bits/stdc++.h>
using namespace std;

int n,m,r,c,d;
int board[50][50];
int vis[50][50]; //청소 여부
pair<int,int> cleaner;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r >> c >> d;
    
    for(int i=0; i<n; i++) {
        fill(vis[i],vis[i]+m,-1);
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    cleaner = {r,c};
    vis[r][c] = 1;
    while(true) {
        // if(d==0)
    }    
}