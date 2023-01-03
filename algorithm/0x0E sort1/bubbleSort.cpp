#include <bits/stdc++.h>
using namespace std;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[10] = {3,2,7,116,62,235,1,23,55,77};
    int n = 10;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }

    for(int i=0; i<10; i++) {
        cout << arr[i] << ' ';
    }
    
}