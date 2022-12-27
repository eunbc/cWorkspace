#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[10][10];
vector<pair<int,int>> room;
vector<pair<int,int>> virus;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs() {
    int tmp[10][10];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            tmp[i][j] = board[i][j];
        }
    }

    cout << "==================tmp\n";

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << tmp[i][j];
        }
        cout << '\n';
    }

    cout << "==================\n";

    queue<pair<int,int>> Q;
    for(int i=0; i<virus.size(); i++) {
        Q.push({virus[i].first,virus[i].second});
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for(int dir=0; dir<4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];        
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(tmp[nx][ny]!=0) continue;
                tmp[nx][ny] = 2;
                Q.push({nx,ny});
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << tmp[i][j];
        }
        cout << '\n';
    }


    int res = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(tmp[i][j]==0) res++;
        }
    }

    return res;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j]==0) room.push_back({i,j});
            if(board[i][j]==2) virus.push_back({i,j});
        }
    }

    int ans = 0;
    for(int i=0; i<room.size(); i++) {
        cout << "room["<< i<< "] = " <<room[i].first << ' ' << room[i].second << '\n';
        board[room[i].first][room[i].second] = 1;
        for(int j=i+1; j<room.size(); j++) {
            board[room[j].first][room[j].second] = 1;
            for(int k=j+1; i<room.size(); k++) {
                board[room[k].first][room[k].second] = 1;
                
                ans = max(ans, bfs());

                board[room[k].first][room[k].second] = 0;
            }
            board[room[j].first][room[j].second] = 0;
        }
        board[room[i].first][room[i].second] = 0;
    }
    
    cout << ans;
    
}