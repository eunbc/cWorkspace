#include <bits/stdc++.h>
using namespace std;

//뉴스 클러스터링
//https://school.programmers.co.kr/learn/courses/30/lessons/17677

string getString(string str) {
    string s = "";
    for(int i=0; i<str.size(); i++) {
        if(isalpha(str[i])) s += toupper(str[i]);
    }
    return s;
}

unordered_map<string,int> getSet(string s) {
    unordered_map<string,int> m;
    for(int i=0; i<s.size()-1; i++) {
        string st;
        st += s[i];
        st += s[i+1];
        m[st]++;
    }
    return m;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    string s1 = getString(str1);
    string s2 = getString (str2);

    cout << s1 << ',' << s2;

    unordered_map<string,int> m1 = getSet(s1);
    unordered_map<string,int> m2 = getSet(s2);

    int kyo = 0, hap = 0;
    for(auto ma1 : m1) {
        for(auto ma2 : m2) {
            if(ma1.first==ma2.first) {
                kyo += min(ma1.second, ma2.second);
                hap += max(ma1.second, ma2.second);
            } else {
                hap += ma1.second;
                hap += ma2.second;
            }
        }
    }

    cout << kyo << ',' << hap << '\n';
    answer = kyo/hap * 65536;
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";
    cout << solution(str1,str2);    
}