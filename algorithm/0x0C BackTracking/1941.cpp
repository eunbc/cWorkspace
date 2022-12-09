#include <bits/stdc++.h>
using namespace std;

int cnt;
char arr[5][5];
bool princess[5][5];

bool check() {
    return true;
}

void func(int k, int x, int y) {
    if(k==7) {
        cnt++;
        return;
    }
    for(int i=x; i<5; i++) {
        for(int j=y; j<5; j++) {
            if(!princess[i][j]) {
                princess[i][j] = true;
                func(k+1,x+1,y);
                func(k+1,x,y+1);
                princess[i][j] = false;
            }       
        }
    }
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<5; i++) {
        string str;
        cin >> str;
        for(int j=0; j<5; j++) {
            arr[i][j] = str[j];
        }
    }
    func(0,0,0);
    cout << cnt;    
}