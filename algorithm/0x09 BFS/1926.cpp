#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool vis[502][502];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> answer;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    int width;
    queue<pair<int,int>> Q;
    for(int i=0;i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 1 && vis[i][j] == 0) {
                vis[i][j] = 1;
                Q.push({i,j});
                width = 1;
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                        width++;
                    }
                }
                answer.push_back(width);
            }
        }
    }

    if(answer.size()==0) cout << 0 << '\n' << 0;
    else {
        cout << answer.size() << '\n' << *max_element(answer.begin(),answer.end());
    } 
    
}