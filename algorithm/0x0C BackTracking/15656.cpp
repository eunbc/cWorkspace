#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10],print[10];

void func(int k) {
    if(k==m) {
        for(int i=0; i<m; i++) {
            cout << print[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++) {
        print[k] = arr[i];
        func(k+1);
    }
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    func(0);
}