#include <bits/stdc++.h>
using namespace std;

//최대값과 최솟값
//https://school.programmers.co.kr/learn/courses/30/lessons/12939

string solution(string s) {
    string answer = "";
    istringstream ss(s);
    string stringBuffer;
    vector<string> x;
    x.clear();
    while (getline(ss, stringBuffer, ' ')){
        x.push_back(stringBuffer);
    }

    vector<int> v;
    for(int i=0; i<x.size(); i++) {
        v.push_back(stoi(x[i]));
    }

    int mn = *min_element(v.begin(), v.end());
    int mx = *max_element(v.begin(), v.end());
    answer = to_string(mn) + ' ' + to_string(mx);
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solution("-1 -2 -3 -4");   
}