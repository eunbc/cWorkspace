#include <bits/stdc++.h>
using namespace std;

int n,k;
int dist[200001];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(dist,dist+200001,-1);
    queue<int> Q;
    dist[n] = 0;
    Q.push(n);
    while(dist[k]==-1) {
        int cur = Q.front(); Q.pop();
        for(int i : {cur-1, cur+1, 2*cur}) {
            if(i<0 || i>200001) continue;
            if(dist[i]>=0) continue;
            dist[i] = dist[cur] + 1;
            Q.push(i);
        }
    }
    cout << dist[k];
    
}