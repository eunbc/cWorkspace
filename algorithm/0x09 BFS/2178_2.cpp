#include <bits/stdc++.h>
using namespace std;

int board[102][102];
int dist[102][102];
int n,m;
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
    dist[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 1 || board[nx][ny]!=1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }

    cout << dist[n-1][m-1];
}