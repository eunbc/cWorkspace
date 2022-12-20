#include <bits/stdc++.h>
using namespace std;

int n,m;
int board1[10][10];
int board2[10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> cctv;

bool OOB(int a, int b) {
    return a<0 || a>=n || b<0 || b>=m; 
}

void udp(int x, int y, int dir) {
    while(true) {
        x += dx[dir];
        y += dy[dir];
        if(OOB(x,y) || board1[x][y]==6) return;
        if(board1[x][y]!=0) continue;
        board2[x][y] = 7;
    }
}


int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int mn = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board1[i][j];
            if(board1[i][j]!=0 && board1[i][j]!=6) 
                cctv.push_back({i,j});
            if(board1[i][j]==0) mn++;
        }
    }

    for(int tmp=0; tmp<64; tmp++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                board2[i][j] = board1[i][j];
            }
        }

        int brute = tmp;
        for(int i=0; i<3; i++) {
            int dir = brute%4;
            brute /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;
            if(board1[x][y]==1) {
                udp(x,y,dir);
            }
        }
    }

    

    return 0;
    

  
}