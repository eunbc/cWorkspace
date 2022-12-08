#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr(n);
int print[10];

void func(int k) {
    if(k==m) {
        for(int i=0; i<m; i++) {
            cout << print[i] << ' ';
        }
        cout << '\n';
        return;
    }
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()),arr.end());
    func(0);
}