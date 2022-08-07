#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x,y,z;
    cin >> x >> y >> z;
    int a,b,c;
    c = max({x,y,z});
    a = min({x,y,z});
    b = x+y+z-a-c;
    cout << a << ' ' << b << ' ' << c;
}
