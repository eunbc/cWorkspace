#include <bits/stdc++.h>
using namespace std;

int n,m,h;
int board[100][100][100];
bool vis[100][100][100];
int res[100][100][100];
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> h;

    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; i++) {
                res[i][j][k] = -1;
            }
        }
    }
 
}