#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10],print[10];

void func(int k,int v) {
    if(k==m) {
        for(int i=0; i<m; i++) {
            cout << print[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    int st = 0;
    if(k!=0) st = v;
    for(int i=st; i<n; i++) {
        if(tmp!=arr[i]) {
            print[k] = arr[i];
            tmp = arr[i];
            func(k+1, i);
        }
    }

}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    func(0,0);
}