#include <bits/stdc++.h>
using namespace std;

int t,n,m,k;
int board[50][50];
bool vis[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    int answer[t];
    for(int i=0; i<t; i++) {
        cin >> n >> m >> k;
        for(int i=0; i<k; i++) {
            int x,y;
            cin >> x >> y;
            board[x][y] = 1;
        }

        int cnt = 0;
        queue<pair<int,int>> Q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]==0 || vis[i][j]) continue;
                vis[i][j] = true;
                cnt++;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny]==0 || vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        answer[i] = cnt;

        for(int i=0; i<n; i++) {
            fill(board[i],board[i]+m,0);
            fill(vis[i],vis[i]+m,false);
        }
    }

    for(int i=0; i<t; i++) {
        cout << answer[i] << '\n';
    }

}