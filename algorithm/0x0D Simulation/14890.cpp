#include <bits/stdc++.h>
using namespace std;

int n,l;
int board[100][100];

bool func(int order, int dir) {
    vector<int> line = {};
    for(int i=0; i<n; i++) {
        if(dir==0) {
            line.push_back(board[order][i]);
        } else if(dir==1) {
            line.push_back(board[i][order]);
        }
    }

    int idx = 0;
    bool res = true;
    int cnt = 1;
    while(idx < n-1) {
        //단차가 1 초과할 경우
        if(abs(line[idx]-line[idx+1])>1) return 0;

        if(line[idx]==line[idx+1]) {
            cnt++;
            idx++;
        } else if(line[idx]<line[idx+1]) {
            if(cnt<l) return 0;
            cnt = 1;
            idx++;
        } else if(line[idx]>line[idx+1]) {
            if(idx + l >= n) return 0;    
            for(int i=idx + 1; i<idx+l; i++) {
                if(line[i]!=line[i+1]) return 0;
            }
            idx = idx + l;
            cnt = 0;
        }
    }
    return res;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<2; j++) {
            if(func(i,j)) cnt++;
        }
    }
    cout << cnt;
    
}