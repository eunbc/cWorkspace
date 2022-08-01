#include <bits/stdc++.h>
using namespace std;

int x;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    if(x>=90) cout << 'A';
    else if(x>=80) cout << 'B';
    else if(x>=70) cout << 'C';
    else if(x>=60) cout << 'D';
    else cout << 'F';
}