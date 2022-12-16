#include <bits/stdc++.h>
using namespace std;

int n,cnt;
int board[30][30];
bool vis[30][30];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<n; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    queue<pair<int,int>> Q;
    vector<int> v;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j]==0 || vis[i][j]) continue;
            vis[i][j] = true;
            cnt++;
            int size = 1;
            Q.push({i,j});
            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir<4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny]==0 || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    size++;
                    Q.push({nx,ny});
                }
            }
            v.push_back(size);
        }
    }

    cout << cnt << '\n';

    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << '\n';
    }

}