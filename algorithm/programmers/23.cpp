#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<string,int> map;
    string tmp; 
    for(int i=0; i<s.size(); i++) {
        if(!isdigit(s[i])) continue;
        else if(isdigit(s[i])) tmp += s[i];
        if(isdigit(s[i+1])) continue;
        map[tmp]++;
        tmp = "";
    }

    int cnt = -1;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='}') cnt++; 
    }

    while(cnt>0) {
        for(auto m : map) {
            if(m.second==cnt) answer.push_back(stoi(m.first));
        }
        cnt--;
    }
    return answer;
}

int main(void){ 

    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}"; 
    vector<int> res = solution(s);
    for(auto r : res) {
        cout << r << ' ';
    }
}