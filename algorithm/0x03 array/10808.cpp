#include <bits/stdc++.h>
using namespace std;

string s;
int a[26];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    
    for(auto c : s) {
        a[c-'a']++;
    } 
    for(int i=0;i<26;i++) cout << a[i] << ' ';
}