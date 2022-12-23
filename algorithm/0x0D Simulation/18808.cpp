#include <bits/stdc++.h>
using namespace std;

int n,m,k,r,c;
int note[40][40];
int sticker[10][10];

bool ispastable(int x, int y) {
    //붙일 수 있는지 확인
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(note[x+i][y+j]==1 && sticker[i][j]==1) {
                return false; 
            }
        }
    }
    //붙이기
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(sticker[i][j]==1) note[x+i][y+j] = 1;
        }
    }

    return true;
}

void rotate() {
    int tmp[10][10];

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }
    
    //90도 회전
    for(int i=0; i<c; i++) {
        for(int j=0; j<r; j++) {
            sticker[i][j] = tmp[r-1-j][i]; 
        }
    }

    //스티커 가로 세로 바꾸기
    swap(r,c);

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
        for(int dir=0; dir<4; dir++) {
            bool paste = false;
            //붙일 수 있는지 확인하고 붙이기 - 못붙이면 회전
            for(int i=0; i<=n-r; i++) { //스티커를 어느 영역에 붙일 수 있는가 
                if(paste) break;
                for(int j=0; j<=m-c; j++) {
                    if(ispastable(i,j)) {
                        paste = true;
                        break;
                    }
                }
            }  
            if(paste) break;
            rotate();             
        }          
    }


    int res = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(note[i][j]==1) res++;
        }
    }

    cout << res ;
    
}