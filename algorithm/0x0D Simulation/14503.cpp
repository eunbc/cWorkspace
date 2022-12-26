#include <bits/stdc++.h>
using namespace std;

int n,m,r,c,d;
int board[51][51];
int dx[4] = {-1,0,1,0}; 
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

    //r,c 청소기의 좌표
    while(true) {
        //1. 현재 위치를 청소한다
        if(board[r][c]==0) board[r][c] = -1;
        //2. 왼쪽 방향에 청소하지 않은 공간으로 회전
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
        // /네 방향 모두가 청소가 되어있거나 벽인 경우
        if(!clean) {
            if(board[r-dx[d]][c-dy[d]]==1) break;//후진했을 때 벽이면 종료
            r -= dx[d]; //후진
            c -= dy[d];
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j]==-1) cnt++;
        }
    }

    cout << cnt;
}