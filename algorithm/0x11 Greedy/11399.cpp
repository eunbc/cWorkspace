#include <bits/stdc++.h>
using namespace std;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[1005];
    for(int i=0; i<n; i++) {
        cin >> p[i];
    }
    
    sort(p,p+n);
    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            answer += p[j];
        }
    }
    cout << answer;
}