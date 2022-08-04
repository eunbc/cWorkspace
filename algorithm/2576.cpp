#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x = 0,sum = 0,min = 100;

    for(int i=0; i<7; i++) {
        cin >> x;
        if(x%2==1) {
            sum += x;
            if(x<min) min = x;
        } 
    }

    if(sum==0) cout << "-1";
    else {
        cout << sum << '\n';
        cout << min;
    }
    
}