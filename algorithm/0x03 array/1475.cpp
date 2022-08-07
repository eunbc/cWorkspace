#include <bits/stdc++.h>
using namespace std;

int n, a[10];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n>0) {
        if(n%10 == 6 || n%10 ==9) a[6]++;
        else a[n%10]++;
        n/=10;
    }

    if(a[6]%2==1) a[6] = a[6]/2 + 1; 
    else a[6] = a[6]/2;
    
    int max = *max_element(a,a+10);
    
    cout << max;
}
