#include <bits/stdc++.h>
using namespace std;

int L,R,C;
char board[30][30][30];
int dist[30][30][30];
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0) return 0;

        queue<tuple<int,int,int>> Q = queue<tuple<int,int,int>>();
        int a=0, b=0, c=0;
        fill_n( &dist[0][0][0], 30*30*30, -1);


        for(int i=0; i<L; i++) {
            for(int j=0; j<R; j++) {
                string str;
                cin >> str;
                for(int k=0; k<C; k++) {
                    board[i][j][k] = str[k];
                    if(board[i][j][k]=='S') {
                        dist[i][j][k] = 0;
                        Q.push({i,j,k});
                    } else if(board[i][j][k]=='E') {
                        a=i;
                        b=j;
                        c=k;
                    }
                }
            }
        }

        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<6; dir++) {
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur) + dy[dir];
                int nz = get<2>(cur) + dz[dir];
                if(nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;
                if(board[nx][ny][nz]=='#' || dist[nx][ny][nz]>=0) continue;
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                Q.push({nx,ny,nz});
            }
        }

        if(dist[a][b][c]!=-1) {
            cout << "Escaped in " << dist[a][b][c] <<  " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }

    }
}