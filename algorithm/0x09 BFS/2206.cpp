#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[1000][1000];
int dist[1000][1000];
bool vis[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    queue<pair<int,int>> Q;
    bool isused = false; //벽을 부수는 기회
    vis[0][0] = true;
    dist[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        bool ispossible = false; //움직일 수 있나?
        for(int dir=0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] > 0 || board[nx][ny]==1) continue;
            ispossible = true;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
        //움직이지도 못하고, 부술 기회는 남아 있을 경우 부순다.
        if(!ispossible && !isused) {
            isused = true;
            for(int dir=0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(dist[nx][ny] > 0) continue;
                board[nx][ny] = 0;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
        } 
    }

    if(dist[n-1][m-1]==0) cout << "-1";
    else cout << dist[n-1][m-1];
}