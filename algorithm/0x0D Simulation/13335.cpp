#include <bits/stdc++.h>
using namespace std;

int n, w, L;
int a[1000];
int cross[1000];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> L;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }    
    cross[0] = 1;
    int sum = a[0];
    int idx = 0;
    // for(int i=1; i<n; i++) {
    //     while(i-idx+1 > w || sum +)
    // }
}