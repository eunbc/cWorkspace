#include <bits/stdc++.h>
using namespace std;

int n;
int board[25][25];
int mn = 0x7f7f7f7f;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }    
    
    vector<int> v(n, 1);
    fill(v.begin(), v.begin() + n/2, 0);
    do{
        int diff = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(v[i]!=v[j]) continue;
                if(v[i]==0) diff += (board[i][j]+board[j][i]);
                else diff -= (board[i][j]+board[j][i]);
            }
        }
        mn = min(mn , abs(diff));
    }while(next_permutation(v.begin(),v.end()));

    cout << mn;
}