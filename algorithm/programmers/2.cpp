#include <bits/stdc++.h>
using namespace std;

//JadenCase 문자열 만들기
//https://school.programmers.co.kr/learn/courses/30/lessons/12951

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    for(int i=0; i<s.size(); i++) {
        if(isFirst) {
            s[i] = toupper(s[i]);
            isFirst = false;
        } else if(s[i]==' ' && s[i+1]!=' ') {
            isFirst = true;
        } else {
            s[i] = tolower(s[i]);
        }
    }
    answer = s;
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str = "for the  last week";
    cout << solution(str);    
}