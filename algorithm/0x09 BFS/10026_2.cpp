#include <bits/stdc++.h>
using namespace std;

int n,color,uncolor;
char board[100][100];
bool vis[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<n; j++) {
            board[i][j] = str[j];
        }
    }

    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]) continue;
            color++;
            vis[i][j] = true;
            Q1.push({i,j});
            while(!Q1.empty()) {
                pair<int,int> cur = Q1.front(); Q1.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[cur.first][cur.second]!=board[nx][ny] || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q1.push({nx,ny});
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        fill(vis[i], vis[i]+n, false);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]) continue;
            uncolor++;
            vis[i][j] = true;
            Q2.push({i,j});
            while(!Q2.empty()) {
                pair<int,int> cur = Q2.front(); Q2.pop();
                for(int dir=0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if((board[cur.first][cur.second]=='R' || board[cur.first][cur.second]=='G') && board[nx][ny]=='B' ||
                     board[cur.first][cur.second]=='B' && (board[nx][ny]=='R' || board[nx][ny]=='G') ||
                     vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q2.push({nx,ny});
                }
            }
        }
    }

    cout << color << '\n' << uncolor;


}