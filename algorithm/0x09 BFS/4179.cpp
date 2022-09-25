#include <bits/stdc++.h>
using namespace std;

char board[1001][1001];
int fire[1001][1001];
int vis[1001][1001];
int r,c;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> q;
    queue<pair<int,int>> jq;
    cin >> r >> c;
    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            cin >> board[j][i];
            if(board[j][i]=='F') q.push({j,i});
            else if(board[j][i]=='J') jq.push({j,i});
        }
    }

    //불
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(board[nx][ny]=='F' || board[nx][ny]=='#' || fire[nx][ny] > 0) continue;
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }

    //지훈
    while(!jq.empty()) {
        auto cur = jq.front(); jq.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(board[nx][ny]!='.' || vis[nx][ny] > 0) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            jq.push({nx,ny});
        }
    }

    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            cout << fire[j][i];
        }
        cout << '\n';
    }

    cout << "=====================" << '\n';

    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            cout << vis[j][i];
        }
        cout << '\n';
    }
    
    
}