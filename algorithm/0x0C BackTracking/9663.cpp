#include <bits/stdc++.h>
using namespace std;

int n,cnt;
bool isused1[30];
bool isused2[30];
bool isused3[30];

void func(int cur) {
    if(cur==n) {
        cnt++;
        return;
    }
    for(int i=0; i<n; i++) {
        if(isused1[i] || isused2[cur+i] || isused3[cur-i+n-1]) {
            continue;
        }
        isused1[i] = true;
        isused2[cur+i] = true;
        isused3[cur-i+n-1] = true;
        func(cur+1);
        isused1[i] = false;
        isused2[cur+i] = false;
        isused3[cur-i+n-1] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}