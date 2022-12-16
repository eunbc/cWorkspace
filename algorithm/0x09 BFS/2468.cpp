#include <bits/stdc++.h>
using namespace std;

int n;
int board[100][100];
bool vis[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int,int>> Q;
    int maximum = 0;
    int h = 100;
    while(h--) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]<=h || vis[i][j]) continue;
                vis[i][j] = true;
                cnt++;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny]<= h || vis[nx][ny]) continue;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        for(int i=0; i<n; i++) {
            fill(vis[i],vis[i]+n,false);
        }
        maximum = max(maximum, cnt) ;
    }
    cout << maximum;
}