#include <bits/stdc++.h>
using namespace std;

string board[101];
bool vis[101][101];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++) cin >> board[i];

    queue<pair<int,int>> Q;

    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j] != 1) {
                vis[i][j] = 1;
                Q.push({i,j});

                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(vis[nx][ny] || board[nx][ny] != board[cur.first][cur.second]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }  
                sum++; 
            }
        }
    }
    cout << sum << ' ';

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) vis[i][j] = 0;
    }

    int sum2 = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j] != 1) {
                vis[i][j] = 1;
                Q.push({i,j});

                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(vis[nx][ny] || (board[nx][ny] == 'B' && board[cur.first][cur.second] != 'B') || (board[nx][ny] != 'B' && board[cur.first][cur.second] == 'B') ) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }  
                sum2++; 
            }
        }
    }
    cout << sum2;
}