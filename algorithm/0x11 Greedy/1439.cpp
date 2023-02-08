#include <bits/stdc++.h>
using namespace std;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int a=0,b=0;
    if(s[0]=='1') a++;
    else if(s[0]=='0') b++; 
    for(int i=1; i<s.size(); i++) {
        if(s[i-1] != s[i] && s[i] == '1') a++;
        else if(s[i-1] != s[i] && s[i]=='0') b++; 
    }
    int answer = min(a,b);    
    cout << answer;
}