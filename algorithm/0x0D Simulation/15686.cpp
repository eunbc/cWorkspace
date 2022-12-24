#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[50][50];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            if(board[i][j]==1) house.push_back({i,j});
            if(board[i][j]==2) chicken.push_back({i,j});
        }
    }
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m , 0);

    int res = 0x7f7f7f7f;
    do{
        int city = 0;
        for(int i=0; i<house.size(); i++) {
            int dist = 0x7f7f7f7f; 
            for(int j=0; j<chicken.size(); j++) {
                if(brute[j]==0) continue;
                int tmp = abs(house[i].first-chicken[j].first) + abs(house[i].second-chicken[j].second);
                dist = min(dist, tmp);
            } 
            city += dist;
        }
        res = min(res, city);
    } while(next_permutation(brute.begin(), brute.end()));
    
    cout << res;
}