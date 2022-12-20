#include <bits/stdc++.h>
using namespace std;

int t;
int board[300][300];
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
queue<pair<int,int>> Q;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int l, a, b, x, y;
        cin >> l >> a >> b >> x >> y;
        Q = queue<pair<int,int>>();
        for(int i=0; i<l; i++) {
            fill(board[i], board[i]+l, -1);
        }
        board[a][b] = 0;
        Q.push({a,b});
        while(!Q.empty()) {
            if(board[x][y]!=-1) {
                cout << board[x][y] << '\n';
                break;
            }
            pair<int,int> cur = Q.front(); Q.pop();
            for(int dir=0; dir<8; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(board[nx][ny]>=0) continue;
                board[nx][ny] = board[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
        }
    }
    
    

}