#include <bits/stdc++.h>
using namespace std;

int t, w, h;
char board[1000][1000];
int fire[1000][1000], dist[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
vector<string> arr;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    
    while(t--) {
        queue<pair<int,int>> Q1 = {};
        queue<pair<int,int>> Q2 = {};

        cin >> w >> h;
        for(int i=0; i<h; i++) {
            cin >> board[i];
            fill(fire[i], fire[i]+1000, -1);
            fill(dist[i], dist[i]+1000, -1);
            for(int j=0; j<w; j++) {
                if(board[i][j]=='*') {
                    fire[i][j] = 0;
                    Q1.push({i,j});
                } else if(board[i][j]=='@') {
                    dist[i][j] = 0;
                    Q2.push({i,j});
                }
            }        
        }



        //불 전파
        while(!Q1.empty()) {
            pair<int,int> cur = Q1.front(); Q1.pop();
            for(int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(fire[nx][ny]>=0 || board[nx][ny]=='#') continue;
                fire[nx][ny] = fire[cur.first][cur.second] + 1;
                Q1.push({nx,ny});
            }
        }


        bool possible = false;
        while(!Q2.empty() && !possible) {
            pair<int,int> cur = Q2.front(); Q2.pop();
            for(int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    possible = true;   
                    int num = dist[cur.first][cur.second] + 1;
                    arr.push_back(to_string(num));
                    break;
                }    
                if(dist[nx][ny]>=0 || board[nx][ny]=='#') continue;
                if(fire[nx][ny]!=-1 && fire[nx][ny] <= dist[cur.first][cur.second] + 1) continue;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q2.push({nx,ny});
            }
        }
        if(!possible) arr.push_back("IMPOSSIBLE");
    }

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << '\n';
    }

}