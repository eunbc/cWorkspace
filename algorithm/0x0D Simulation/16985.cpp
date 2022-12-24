#include <bits/stdc++.h>
using namespace std;

int board1[5][5][5];
int board2[5][5][5];
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

void init() {
    for(int k=0; k<5; k++) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                board2[k][i][j] == board1[k][i][j];
            }
        }
    }    
}

void rotate(int k, int dir) {
    int tmp[1][5][5];
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            tmp[1][i][j] = board2[k][i][j];
        }
    }

    if(dir==0) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                board2[k][i][j] = tmp[1][i][j];
            }
        }
    } else if (dir==1){
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                board2[k][i][j] = tmp[1][i][j];
            }
        }
    } else if (dir==2){
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                board2[k][i][j] = tmp[1][i][j];
            }
        }
    } else if (dir==3){
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                board2[k][i][j] = tmp[1][i][j];
            }
        }
    }    
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int k=0; k<5; k++) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                cin >> board1[k][i][j];
            }
        }
    }

    int res = 0x7f7f7f7f;
    for(int tmp=0; tmp<(1<<2*5); tmp++) {
        init();        
        int brute = tmp;
        //각각의 경우의 수에 맞게 회전 시킨 다음
        for(int k=0; k<5; k++) {
            int dir = brute % 4;
            brute /= 4;
            rotate(k, dir);
        }
        int dist = 0x7f7f7f7f;
        //입구에서 출구로 가는 최단거리, 각각의 꼭지점
        for(int i=0; i<8; i++) {
            
        }

    }
}