#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[200002];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(dist, dist+200002 , -1);
    dist[n] = 0;
    deque<int> Q;
    Q.push_back(n);

    while(dist[k]==-1) {
        int cur = Q.front(); Q.pop_front();
        if(2*cur < 0 || 2*cur > 200000) continue;
        if(dist[2*cur]>-1) continue;
        dist[2*cur] = dist[cur];
        Q.push_front(2*cur);

        for(int i : {cur-1, cur+1}) {
            if(i < 0 || i > 200000) continue;
            if(dist[i]>-1) continue;
            dist[i] = dist[cur] + 1;  
            Q.push_back(i);  
        }
    }

    cout << dist[k];
    
}