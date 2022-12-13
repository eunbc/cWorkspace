#include <bits/stdc++.h>
using namespace std;

int r,c;
char board[1000][1000];
int fire[1000][1000],jihoon[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> board[i][j];
            if(board[i][j]=='F') Q1.push({i,j}); 
            if(board[i][j]=='J') Q2.push({i,j}); 

        }
    }

    while(!Q1.empty()) {
        pair<int,int> cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny]=='#' || board[nx][ny] == 'F' || fire[nx][ny] > 0) continue;
            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            Q1.push({nx,ny}); 
        }
    } 

    while(!Q2.empty()) {
        pair<int,int> cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(board[nx][ny]=='#' || board[nx][ny] == 'J' || jihoon[nx][ny] > 0) continue;
            jihoon[nx][ny] = jihoon[cur.first][cur.second] + 1;
            Q2.push({nx,ny}); 
        }
    } 
    

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << fire[i][j];
        }
        cout << '\n';
    }

    cout << "===========================\n";

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << jihoon[i][j];
        }
        cout << '\n';
    }
}