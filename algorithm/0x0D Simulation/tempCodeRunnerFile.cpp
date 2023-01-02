#include <bits/stdc++.h>
using namespace std;

string arr[4];
int k;

void go(int n, int d) {
    int dirs[4] = {};
    dirs[n] = d;
    int idx = n;
    //왼쪽
    while(idx > 0 && arr[idx][6] != arr[idx-1][2]) {
        dirs[n-1] = -dirs[n];
        idx--;            
    }
    idx = n;
    //오른쪽
    while(idx < 3 && arr[idx][2] != arr[idx+1][6]) {
        dirs[n+1] = -dirs[n];
        idx++;
    }


    for(int i=0; i<4; i++) {
        if(dirs[i]==-1) {
            rotate(arr[i].begin(),arr[i].begin()+1,arr[i].end());
        } else if(dirs[i]==1) {
            rotate(arr[i].begin(),arr[i].begin()+7,arr[i].end());            
        }
    }
}

int main(void){ 
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    for(int i=0; i<4; i++) {
        cin >> arr[i]; 
    }
    
    cin >> k;
    while(k--) {
        int num,dir;
        cin >> num >> dir;
        go(num-1,dir);
    }

    int ans = 0;

    for(int i=0; i<4; i++) {
        if(arr[i][0]=='1') ans += (1<<i);
    };

    cout << ans;
}