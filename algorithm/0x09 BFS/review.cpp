#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[1000][1000];
int fire[1000][1000];
int jihoon[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;

    for(int i=0; i<n; i++) {
        fill(fire[i],fire[i]+m,-1);
        fill(jihoon[i],jihoon[i]+m,-1);

        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            board[i][j] = str[j];
            if(board[i][j]=='F') {
                fire[i][j] = 0;
                Q1.push({i,j});
            } 
            else if(board[i][j]=='J') {
                jihoon[i][j] = 0;
                Q2.push({i,j});
            } 
        }
    }


    // for(int i=0; i<n; i++) {
    //     fill(dist[i], dist[i]+m, -1);
    //     for(int j=0; j<m; j++) {
    //         cin >> board[i][j];
    //         if(board[i][j]==1) {
    //             dist[i][j]=0;
    //             Q.push({i,j});
    //         }
    //     }
    // }


    //불의 속도
    while(!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '#' || fire[nx][ny]>=0) continue;
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            Q1.push({nx,ny});  
        }
    }

    // cout << "==========fire===============\n";
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << fire[i][j];
    //     }
    //     cout << '\n';
    // }

    //지훈의 속도
    bool exit = false;
    while(!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << jihoon[cur.first][cur.second] + 1;
                exit = true;
                break;
            }
            if( board[nx][ny] == '#' || (fire[nx][ny]!= -1 && fire[nx][ny]<=jihoon[cur.first][cur.second] + 1) || jihoon[nx][ny]>=0) continue;
            jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
            Q2.push({nx,ny});  
        }
        if(exit) break;
    }
    if(!exit) cout << "IMPOSSIBLE";

    // cout << '\n';

    // cout << "===========jihoon==============\n";
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout << jihoon[i][j];
    //     }
    //     cout << '\n';
    // }


    // int day = 0; 
    // bool exception = false;
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         if(board[i][j]==0 && dist[i][j]==-1) exception = true;
    //         else {
    //             day = max(day, dist[i][j]);
    //         }
    //     }
    // }    

    // if(exception) cout << "-1";
    // else cout << day;
}