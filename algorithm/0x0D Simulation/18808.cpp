#include <bits/stdc++.h>
using namespace std;

int n,m,k,r,c;
int note[40][40];
int sticker[10][10];

void rotate() {
    int tmp[10][10];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }

    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            sticker[i][j] = tmp[r-1-j][i]; //90도 회전시 i,j값이 규칙적으로 바뀜
        }
    }
    swap(r,c); 
}

bool ispastable(int x, int y) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(note[x+i][y+j]==1 && sticker[i][j]==1) return false;
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(sticker[i][j]==1) note[x+i][y+j]=1; 
        }
    }
    return true;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    while(k--) {
        cin >> r >> c;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> sticker[i][j];
            }
        }
        
        bool paste = false;
        for(int dir=0; dir<4; dir++) {
            for(int i=0; i<=n-r; i++) { //스티커를 붙일 수 있는 노트의 범위
                for(int j=0; j<=m-c; j++) {
                    if(ispastable(i,j)) {
                        paste = true;
                        break;
                    }
                }
                if(paste) break;
            }
            if(paste) break;
            rotate();
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cnt += note[i][j];
        }
    }

    cout << cnt;
    
}