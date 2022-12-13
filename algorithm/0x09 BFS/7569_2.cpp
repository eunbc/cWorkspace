#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];
int vis[1000][1000];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int,int>> Q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j]==1) Q.push({i,j});
        }
    }

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny]!=0 || vis[nx][ny] > 0) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            board[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }

    //토마토가 모두 익지는 못하는 상황
    bool zero = false;    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j]==0) {
                zero = true;
                break;
            }
        }
    }

    //모두 익을 때까지의 최소 날짜
    int minimum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            minimum = max(minimum, vis[i][j]);
        }
    }

    if(zero) cout << "-1";
    else cout << minimum;


}