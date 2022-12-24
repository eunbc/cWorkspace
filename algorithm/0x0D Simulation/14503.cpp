#include <bits/stdc++.h>
using namespace std;

int n,m,r,c,d,ans;
int board[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r >> c >> d;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    
    while(true) {
        if(board[r][c]==0) ans++;
        board[r][c] = -1;
        bool clean = false;
        for(int i=0; i<4; i++) {
            d = (d+3) % 4;
            if(board[r+dx[d]][c+dy[d]]==0) {
                r += dx[d];
                c += dy[d];
                clean = true;
                break;                
            } 
        }
        if(clean) continue;
        if(board[r-dx[d]][c-dy[d]]==1) break;
        r -= dx[d];
        c -= dy[d];
    }
    cout << ans;
}