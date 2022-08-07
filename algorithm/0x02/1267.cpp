#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n],y=0,m=0;
    // int a[n],y,m; 지역변수는 초기화하지 않으면 쓰레기값이 들어감
    for(int i=0;i<n;i++) {
        cin >> a[i];
        y += ((a[i]/30)+1)*10;
        m += ((a[i]/60)+1)*15;
    }

    if(y==m) cout << "Y M " << y;
    else if(y>m) cout << "M " << m;
    else if(y<m) cout << "Y " << y; 
    
}