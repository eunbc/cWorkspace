#include <bits/stdc++.h>
using namespace std;


int main()
{
    tuple<int,int,int> cur = {1,2,3};
    int x,y,z;

    tie(x, y, z) = cur;
    cout << x << ' ' << y << ' ' << z;
    return 0;
}

