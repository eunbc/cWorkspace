#include <bits/stdc++.h>
using namespace std;

int board[100][100];
bool vis[100][100];
int m,n,k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;
    while(k--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int i=b; i<d; i++) {
            for(int j=a; j<c; j++) {
                board[i][j] = 1;
            }
        }
    }
    
    queue<pair<int,int>> Q;
    vector<int> v;
    int cnt = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j]==1 || vis[i][j]) continue;
            vis[i][j] = true;
            int size = 1;
            cnt++;
            Q.push({i,j});
            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(board[nx][ny]==1 || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    size++;
                    Q.push({nx,ny});
                }
            }
            v.push_back(size);
        }
    }    

    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}