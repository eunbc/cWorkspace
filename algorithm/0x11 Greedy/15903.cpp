#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[1005];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    while(m--) {
        sort(a, a+n);
        long long tmp = a[0] + a[1];
        a[0] = tmp;
        a[1] = tmp;
    }

    long long answer = 0;
    for(int i=0; i<n; i++) answer += a[i];
    cout << answer;
        
}