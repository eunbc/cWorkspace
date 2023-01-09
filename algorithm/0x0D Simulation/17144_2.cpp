#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int room[55][55];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void spread() {
    int dummy[55][55] = {};
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(room[i][j]<=0) continue;
            for(int dir=0; dir<4; dir++) {
                int x = i+dx[dir];
                int y = j+dy[dir];
                if(x<0 || x>= r || y<0 || y>= c) continue;
                if(room[x][y]==-1) continue;
                dummy[x][y] += room[i][j]/5;
                dummy[i][j] -= room[i][j]/5;
            }
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            room[i][j] += dummy[i][j];
        }
    }
}

void cleaner() {
    //위
    
    //아래
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> t;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> room[i][j];
        }
    }

    cout << "======================\n";
    while(t--) {
        spread();
        cleaner();
    }
    

}