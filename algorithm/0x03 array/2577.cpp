#include <bits/stdc++.h>
using namespace std;

int a,b,c,res[10];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    int n = a*b*c;
    
    while (n>0) {
        res[n%10]++;
        n /= 10;
    }
    for(int i=0;i<10;i++) cout << res[i] << '\n';
}