#include <bits/stdc++.h>
using namespace std;

int board[51][51];
bool vis[51][51];
int t,m,n,k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> m >> n >> k;
        int x=0,y=0;
        while(k--) {
            cin >> x >> y;
            board[y][x] = 1;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
        
        queue<pair<int,int>> Q;
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==1 && vis[i][j]==0) Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx <0 || nx >= m || ny <0 || ny >= n) continue;
                        if(board[nx][ny] != 1 || vis[nx][ny]) continue;
                        vis[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                }
                sum++;
            }
        }

        cout << sum;
    }

    
}