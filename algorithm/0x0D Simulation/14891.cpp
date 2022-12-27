#include <bits/stdc++.h>
using namespace std;

int board[4][8];
int k, num, dir;
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
        

    }
}