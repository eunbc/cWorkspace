#include <bits/stdc++.h>
using namespace std;

int F,S,G,U,D;
int dist[1000001];

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> F >> S >> G >> U >> D;
    fill(dist, dist+1000001 , -1);
    queue<int> Q;
    dist[S] = 0;
    Q.push(S);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(dist[G]!=-1) {
            cout << dist[G];
            return 0;
        }
        for(int i : {cur+U, cur-D}) {
            if(i<1 || i>F) continue;
            if(dist[i]!=-1) continue;
            dist[i] = dist[cur] + 1;
            Q.push(i);
        }
    }
    cout << "use the stairs";
}