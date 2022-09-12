#include <bits/stdc++.h>
using namespace std;

int board[301][301];
bool vis[301][301];
int t,L;
int dx[8] = {-1, -2, -1, -2, 1, 2, 1, 2};
int dy[8] = {-2, -1, 2, 1 ,-2, -1, 2, 1};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> L;
        int a=0,b=0,c=0,d=0;
        cin >> a >> b >> c >> d;
        
        queue<pair<int,int>> Q;
        vis[a][b] = 1;
        board[a][b] = 0;
        Q.push({a,b});

        while(!Q.empty()) {
            pair<int,int> cur = Q.front(); Q.pop();
            for(int dir=0; dir < 8; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                board[nx][ny] = board[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
        }
        
        cout << board[c][d] << '\n';

        for(int i=0; i<L; i++) {
            fill(board[i], board[i]+L, 0);
            fill(vis[i],vis[i]+L,0);
        }    
    }
}