#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[101];
int dist[101][101];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> board[i];
    for(int i = 0; i < n; i++) fill(dist[i]+1,dist[i]+m+1,-1);

    queue<pair<int,int>> Q;
    dist[1][1] = 1;
    Q.push({1,1});

    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(board[nx][ny] != '1' || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X, cur.Y]+1;
            Q.push({nx,ny});
        }
    }

    cout << dist[n,m];

    
}