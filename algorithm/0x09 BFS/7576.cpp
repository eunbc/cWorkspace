#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int dist[1001][1001];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
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
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 0 || dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            board[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }

    int max = 0;
    bool exception = false;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(max<dist[i][j]) max = dist[i][j];
            if(board[i][j]==0) {
                exception = true;
                break;
            }
        }
    }

    //토마토가 모두 익지는 못하는 상황
    if(exception) cout << -1;
    //저장될 때부터 모든 토마토가 익어있는 상태
    else if(max==0) cout << 0;
    else cout << max;
    
}