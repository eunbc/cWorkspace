#include <bits/stdc++.h>
using namespace std;

int n, m;
int board1[10][10], board2[10][10];
vector<pair<int,int>> cctv;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void func(int a, int b, int dir) {
    dir %= 4; //이걸 안해주면 시간 초과. 왜? -> dir로 넣을 수 있는 값은 0,1,2,3인데, dir에 +1,+2,+3,+4 해버리면 dir로 4이상의 수가 넘어올 수 있음 
    while(true) {
        a += dx[dir];
        b += dy[dir];
        if(a<0 || a>=n || b<0 || b>=m) break;
        if(board2[a][b]==6) break;
        if(board2[a][b]!=0) continue; //cctv일 경우 continue
        board2[a][b] = 7;
    }
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int minimum = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board1[i][j];
            if(board1[i][j]!=0 && board1[i][j]!=6) cctv.push_back({i,j});
            if(board1[i][j]==0) minimum++; //cctv가 한 대도 없을 경우 고려
        }
    }

    //4의 (cctv개수)승 만큼의 경우의 수가 존재
    for(int tmp =0 ; tmp < (1<<2*cctv.size()) ; tmp++) {
        //board2 초기화
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                board2[i][j] = board1[i][j];
            }
        }
        int brute = tmp;
        for(int i=0; i<cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;
            if(board1[x][y]==1) {
                func(x, y, dir);
            } else if(board1[x][y]==2) {
                func(x, y, dir);
                func(x, y, dir+2);
            } else if(board1[x][y]==3) {
                func(x, y, dir);
                func(x, y, dir+1);
            } else if(board1[x][y]==4) {
                func(x, y, dir);
                func(x, y, dir+1);
                func(x, y, dir+2);
            } else if(board1[x][y]==5) {
                func(x, y, dir);
                func(x, y, dir+1);
                func(x, y, dir+2);
                func(x, y, dir+3);
            }
        }
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board2[i][j]==0) res++;
            }
        }
        minimum = min(minimum, res);
    }
    cout << minimum;
}