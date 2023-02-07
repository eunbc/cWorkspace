#include <bits/stdc++.h>
using namespace std;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[105];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int answer = 0;
    for(int i=n-1; i>0; --i) {
        while(arr[i-1]>=arr[i]) {
            arr[i-1]--;
            answer++;
        }
    }
    cout << answer;    
}