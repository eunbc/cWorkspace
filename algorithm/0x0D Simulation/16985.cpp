#include <bits/stdc++.h>
using namespace std;

int board[4][5][5][5];
int maze[5][5][5];

int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int solve() {
    if(maze[0][0][0]==0 || maze[4][4][4]==0 ) return 0x7f7f7f7f;
    int dist[5][5][5] = {0,};
    queue<tuple<int,int,int>> Q;
    dist[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<6; dir++) {
            int x,y,z;
            tie(x,y,z) = cur;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if(maze[nx][ny][nz]==0 || dist[nx][ny][nz] > 0) continue;
            if(nx == 4 && ny == 4 && nz == 4) return dist[x][y][z];
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx,ny,nz});
        }
    }
    return 0x7f7f7f7f;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                cin >> board[0][i][j][k];
            }
        }
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                board[1][i][j][k] = board[0][i][4-k][j];
            }
        }
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                board[2][i][j][k] = board[1][i][4-k][j];
            }
        }
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                board[3][i][j][k] = board[2][i][4-k][j];
            }
        }        
    }
    
    int arr[5] = {0,1,2,3,4};
    int ans = 0x7f7f7f7f;
    do{
        for(int tmp=0; tmp<1024; tmp++) {
            int brute = tmp;
            for(int i=0; i<5; i++) {
                int dir = brute % 4;
                brute /= 4;
                for(int j=0; j<5; j++) {
                    for(int k=0; k<5; k++) {
                        maze[i][j][k] = board[dir][arr[i]][j][k];
                    }
                }
            }
            ans = min(ans, solve());
        }
    } while(next_permutation(arr,arr+5));

    if(ans==0x7f7f7f7f) cout << -1;
    else cout << ans;
}