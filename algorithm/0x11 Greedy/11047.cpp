#include <bits/stdc++.h>
using namespace std;

int n,k;
int coin[10];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++) { cin >> coin[i]; }
    int answer = 0;
    for(int i=n-1; i>=0; i--) {
        answer += k/coin[i];
        k %= coin[i];
    }
    cout << answer;

}