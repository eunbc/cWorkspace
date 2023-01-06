#include <bits/stdc++.h>
using namespace std;

int r,c,t;
int a[55][55];
vector<pair<int,int>> cleaner;
vector<pair<int,int>> dust;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void clean(int x, int y, int dir) {
    //위, 반시계 방향
    a[x][y+1] = 0;

    for(int i=c-2; i>1; i--) {
        a[x][i] = a[x][i-1]; 
    }

    // a[x+1][c-1] = a[]
    

}

void spread() {
    vector<tuple<int,int,int>> v = {};
    for(int i=0; i<dust.size(); i++) {
        for(int dir=0; dir<4; dir++) {
            int x = dust[i].first+dir[dx];
            int y = dust[i].second+dir[dy];
            int add = a[dust[i].first][dust[i].second]/5;
            
            if(x<0 || x>=r || y<0 || y>=c) continue;
            if(cleaner[0].first == x && cleaner[0].second == y) continue;
            if(cleaner[1].first == x && cleaner[1].second == y) continue;

            v.push_back({x,y,add});
            v.push_back({dust[i].first, dust[i].second, -add});
        }
    }

    for(int i=0; i<v.size(); i++) {
        int x = get<0>(v[i]);
        int y = get<1>(v[i]);
        int add = get<2>(v[i]);
        
        a[x][y] += add;
        if(a[x][y] < 0) a[x][y] = 0;
    }

    // cout << "\n========================\n";

    // for(int i=0; i<r; i++) {
    //     for(int j=0; j<c; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> t;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
            if(a[i][j]==-1) cleaner.push_back({i,j});
            if(a[i][j]>0) dust.push_back({i,j});
        }
    }

    while(t--) {
        //미세먼지가 확산된다.
        spread();

        //공기청정기가 작동한다.
        //위
        clean(cleaner[0].first, cleaner[0].second, -1);
        //아래
        clean(cleaner[1].first, cleaner[1].second, 1);
    }

    int ans = 0;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(a[i][j]!=-1) ans += a[i][j]; 
        }
    }

    cout << ans;
}