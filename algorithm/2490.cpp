#include <bits/stdc++.h>
using namespace std;

int a[12];
int b[3];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<sizeof a; i++) cin >> a[i];
    for(int i=0; i<4; i++) if(a[i]==1) b[0]++;
    for(int i=4; i<8; i++) if(a[i]==1) b[1]++;
    for(int i=8; i<12; i++) if(a[i]==1) b[2]++;

    for(int i=0; i<sizeof b; i++) {
        switch (b[i]){
        case 0:
            cout << 'D';
            break;
        case 1:
            cout << 'C';
            break;
        case 2:
            cout << 'B';
            break;
        case 3:
            cout << 'A';
            break;
        case 4:
            cout << 'E';
            break;        
        default:
            break;
        }
    }

}