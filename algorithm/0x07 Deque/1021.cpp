#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> dq;
    int n, m, sum = 0;
    cin >> n, m;
    for(int i=1;i<=n;i++) dq.push_back(i);

    while(m--) {
        int a;
        cin >> a;
        int idx = find(dq.begin(),dq.end(),a);
        while(dq.front()!=a) {
            if()
        }

    }
    
}