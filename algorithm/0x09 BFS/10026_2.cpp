#include <bits/stdc++.h>
using namespace std;

int n;
string board[100];
bool vis[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> board[i];
    }
    
    //color
    queue<pair<int,int>> Q;
    int color = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]==1) continue;
            Q.push({i,j});
            vis[i][j]=1;
            color++;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny]!=board[cur.first][cur.second] || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.push({nx,ny});
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        fill(vis[i], vis[i]+n, false);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j]=='G') board[i][j] = 'R';       
        }
    }
    //uncolor
    int uncolor = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]==1) continue;
            Q.push({i,j});
            vis[i][j]=1;
            uncolor++;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny]!=board[cur.first][cur.second] || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.push({nx,ny});
                }
            }
        }
    }

    cout << color << ' ' << uncolor;
    

}