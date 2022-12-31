#include <bits/stdc++.h>
using namespace std;

char board[4][8];
int k, num, dir;

void rotate(int n, int d) {
    
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            cin >> board[i][j];
        }
    }
    
    cin >> k;
    while(k--) {
        int tmp[4][8];
        for(int i=0; i<4; i++) {
            for(int j=0; j<8; j++) {
                tmp[i][j] == board[i][j];
            }
        }
        cin >> num >> dir;
        //왼쪽 돌리기
        if(num > 1 && board[num-2][2]!=board[num-1][6]) rotate(num-2, dir * -1);
        //오른쪽 돌리기
        if(num < 4 && board[num][2]!=board[num-1][6]) rotate(num, dir * -1);

        //n번 바퀴 돌리기
        rotate(num-1, dir);
    }
}