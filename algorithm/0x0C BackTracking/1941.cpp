#include <bits/stdc++.h>
using namespace std;

int cnt;
char arr[5][5];
bool isPrincess[5][5];

bool check() {

}

void func(int k, int x, int y) {
    if(k==7) {
        // bool res = check();
        // if(res) {
            cnt++;
        // }
        return;
    }

    if(!isPrincess[x-1][y]) {
        isPrincess[x-1][y] = true;   
        func(k+1,x-1,y);         
    }
    if(!isPrincess[x][y-1]) {
        isPrincess[x][y-1] = true;   
        func(k+1,x,y-1);         
    }
    if(!isPrincess[x+1][y]) {
        isPrincess[x+1][y] = true;   
        func(k+1,x+1,y);         
    }
    if(!isPrincess[x][y+1]) {
        isPrincess[x][y+1] = true;   
        func(k+1,x,y+1);         
    }
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    for(int i=0; i<5; i++) {
        cin >> str;
        for(int j=0; j<5; j++) {
            arr[i][j] = str[j];
        }
    }
    func(0,0,0);
    cout << cnt;
}