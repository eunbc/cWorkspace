#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000005];
vector<int> v;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    d[1] = 0;
    // v.push_back(1);
    for(int i=2; i<=n; i++) {
        d[i] = d[i-1] + 1;
        if(i%2==0 && d[i]>(d[i/2]+1)) {
            d[i] = d[i/2]+1;
            v.push_back(i/2);
        } else if(i%3==0 && d[i]>(d[i/3]+1)) {
            d[i] = d[i/3]+1;
            v.push_back(i/3);
        } else {
            v.push_back(i-1);
        }
    }

    cout << d[n] << '\n';
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
}