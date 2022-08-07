#include <bits/stdc++.h>
using namespace std;

int a[5], sum;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i=0; i<5; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+5);
    cout << sum/5 << '\n';
    cout << a[2];
}