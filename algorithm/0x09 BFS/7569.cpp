#include <bits/stdc++.h>
using namespace std;

int board[101][101][101];
bool vis[101][101][101];
int m,n,h;
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    queue<tuple<int,int,int>> q;

    for(int i=0; i<h; i++) {
        for(int j=0; j<n ; j++) {
            for(int k=0; k<m; k++) {
                cin >> board[i][j][k];
                if(board[i][j][k]==1 && vis[i][j][k]==0) {
                    q.push({i,j,k});
                    vis[i][j][k]=1;
                } 
            }
        }
    }

    while(!q.empty()) {
        tuple<int,int,int> cur = q.front(); q.pop();
        for(int dir=0; dir<6; dir++) {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >=n || nz < 0 || nz >= m) continue;
            if(vis[nx][ny][nz] || board[nx][ny][nz] < 0) continue;
            board[nx][ny][nz] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            vis[nx][ny][nz] = 1;
            q.push({nx,ny,nz});
        }
    }    
    
    int max = 0;
    bool flag = false;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n ; j++) {
            for(int k=0; k<m; k++) {
                //cout << board[i][j][k];
                if(board[i][j][k]==0) {
                    flag = true;
                    break;
                } else if(board[i][j][k] > max) {
                    max = board[i][j][k];
                }
            }
            //cout << '\n';
        }
    }

    if(flag) cout << -1;
    else if(max==1) cout << 0;
    else cout << max-1; 
}