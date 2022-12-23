#include <bits/stdc++.h>
using namespace std;

int a, b, c;

long long func(int x, int y, int z) {
    
    if(y%2==1) return; //base condition
    
    func(x, y/2, z);
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    func(a, b, c);
}