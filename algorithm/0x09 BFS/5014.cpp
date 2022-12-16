#include <bits/stdc++.h>
using namespace std;

int F,S,G,U,D,cnt;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> F >> S >> G >> U >> D;
    
    queue<int> Q;
    Q.push(S);

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur==G) break;
        
        int selected;

        //올라가는 것
        int up = cur + U;

        //내려가는 것
        int down = cur + (-1)*D;

        //경계값 검사
        if(up > F) selected = down;
        else if(down < 1) selected = up;
        
        if(G-up > G-down) selected = down;
        else if(G-up < G-down) selected = up;

        cnt++;
        Q.push(selected);
    }
    cout << cnt;
}