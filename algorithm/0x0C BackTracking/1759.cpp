#include <bits/stdc++.h>
using namespace std;

int l,c;
char arr[20],print[20];

bool check() {
    int moem = 0;
    int jaem = 0;
    for(int i=0; i<l; i++) {
        if(print[i]=='a'|| print[i]=='e'|| print[i]=='i'|| print[i]=='o'|| print[i]=='u') moem++;
        else jaem++;
    } 
    if(1<=moem && 2<=jaem) return true;
    else return false;
}

void func(int k, int v) {
    if(k==l) {
        bool res = check();
        if(res) {
            for(int i=0; i<l; i++) {
                cout << print[i];
            }
            cout << '\n';
        }
        return;
    }
    int st = 0;
    if(k!=0) st = v+1;
    for(int i=st; i<c; i++) {
        print[k] = arr[i];
        func(k+1, i);
    }
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for(int i=0; i<c; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+c);
    func(0,0);    
}