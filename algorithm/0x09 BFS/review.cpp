#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[1000][1000];
int dist[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int,int>> Q;

    for(int i=0; i<n; i++) {
        fill(dist[i], dist[i]+m, -1);
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j]==1) {
                dist[i][j]=0;
                Q.push({i,j});
            }
        }
    }


    // for(int i=0; i<n; i++) {
    //     string str;
    //     cin >> str;
    //     for(int j=0; j<m; j++) {
    //         board[i][j] = str[j] - '0';
    //     }
    //     fill(dist[i],dist[i]+m,-1);
    // }

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == -1 || dist[nx][ny]>=0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});  
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << dist[i][j];
    //     }
    //     cout << '\n';
    // }

    int day = 0; 
    bool exception = false;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j]==0 && dist[i][j]==-1) exception = true;
            else {
                day = max(day, dist[i][j]);
            }
        }
    }    

    if(exception) cout << "-1";
    else cout << day;
}