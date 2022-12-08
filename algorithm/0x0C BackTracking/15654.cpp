#include <bits/stdc++.h>
using namespace std;

int n,m;
int given[10],arr[10];
bool isused[10];

void func(int k) {
    if(k==m) {
        for(int i=0; i<m; i++) {
            cout <<  arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++) {
        if(!isused[i]) {
            arr[k] = given[i];
            isused[i] = true;
            func(k+1);
            isused[i] = false; 
        }
    }

}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> given[i];
    }
    sort(given, given + n);
    func(0);
}