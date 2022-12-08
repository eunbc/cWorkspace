#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int cur) {
    if(cur==m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int st = 1;
    if(cur!=0) st = arr[cur-1] + 1;
    for(int i=st; i<=n; i++) {
        if(!isused[i]) {
            arr[cur] = i;
            isused[i] = true;
            func(cur+1);
            isused[i] = false;
        }
     }
    
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);    
}