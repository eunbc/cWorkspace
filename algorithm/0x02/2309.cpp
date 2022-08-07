#include <bits/stdc++.h>
using namespace std;

int a[9],total, res;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<9; i++) {
        cin >> a[i];
        total += a[i];
    }
    
    sort(a,a+9);

    for(int i=0;i<8;i++) {
        for(int j=i+1;j<9;j++) {
            res = total -a[i] -a[j];
            if(res==100) {
                for(int k=0;k<9;k++) {
                    if(k==i || k==j) continue;
                    cout << a[k] << '\n';
                }
                break;          
            }
        }
        if(res==100) break; // 가능한 정답이 여러 가지인 경우, 첫번째만 출력
    }
}