#include <bits/stdc++.h>
using namespace std;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a,b;
    for(int i=0; i<n; i++) {
        int aa;
        cin >> aa;
        a.push_back(aa);
    }
    for(int i=0; i<n; i++) {
        int bb;
        cin >> bb;
        b.push_back(bb);
    }

    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(),b.end());

    int answer = 0;
    for(int i=0; i<n; i++) {
        answer += a[i]*b[i];
    }

    cout << answer;

}