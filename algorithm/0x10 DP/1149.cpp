#include <bits/stdc++.h>
using namespace std;

int n;
int cost[1005][3];
int d[1005][3];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            cin >> cost[i][j];
        }
    }

    d[1][0] = cost[1][0];
    d[1][1] = cost[1][1];
    d[1][2] = cost[1][2];
    for(int i=2; i<=n; i++) {
        for(int j=0; j<3; j++) {
            d[i][j] = min(d[i-1][(j+1)%3], d[i-1][(j+2)%3]) + cost[i][j];
        }
    }


    cout << *min_element(d[n], d[n] + 3);

}