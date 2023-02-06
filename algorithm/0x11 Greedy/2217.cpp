#include <bits/stdc++.h>
using namespace std;

int rope[100005];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> rope[i];
    }
    sort(rope, rope+n);
    int answer = 0;
    for(int i=1; i<=n; i++) {
        answer = max(answer, rope[n-i]*i);
    }
    cout << answer;
}