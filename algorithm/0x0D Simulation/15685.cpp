#include <bits/stdc++.h>
using namespace std;

int N;
bool board[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--) {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        vector<int> v = {};
        v.push_back(d%4);
        board[y][x] = 1;

        while(g--) {
            for(int i=v.size()-1; i>=0; i--) {
                v.push_back((v[i]+1)%4);
            }
        }
        
        for(int i=0; i<v.size(); i++) {
            int dir = v[i];
            x += dx[dir];
            y += dy[dir];
            board[y][x] = 1;
        }

    }

    int ans = 0;
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(!board[i][j]) continue;
            if(board[i+1][j] && board[i][j+1] && board[i+1][j+1]) ans++;
        }
    }
    cout << ans;
}