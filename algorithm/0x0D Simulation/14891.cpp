#include <bits/stdc++.h>
using namespace std;

string board[4];

void go(int num, int dir) {
    int dirs[4] = {}; //매번 초기화
    dirs[num] = dir;
    int idx = num;
    //왼쪽 방향
    while(idx > 0 && board[idx][6] != board[idx-1][2]) {
        dirs[idx-1] = -dirs[idx];
        idx--;
    }
    idx = num;
    //오른쪽 방향
    while(idx < 3 && board[idx][2]!= board[idx+1][6]) {
        dirs[idx+1] = -dirs[idx];
        idx++;
    }

    for(int i=0; i<4; i++) {
        if(dirs[i]==-1) { //반시계방향(왼쪽으로 회전)
            rotate(board[i].begin(),board[i].begin()+1, board[i].end());    
        }else if(dirs[i]==1) { //시계방향(오른쪽으로 회전)
            rotate(board[i].rbegin(),board[i].rbegin()+1, board[i].rend());    
        }
    }
    
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    
    for(int i=0; i<4; i++) {
        cin >> board[i];
    }
    cin >> k;
    while(k--) {
        int num, dir;
        cin >> num >> dir;
        go(num-1, dir);
    }
    
    int ans = 0;
    for(int i=0; i<4; i++) {
        if(board[i][0]=='1') ans += (1<<i); //string 이므로 문자로 확인해야 함
    }
    cout << ans;
}