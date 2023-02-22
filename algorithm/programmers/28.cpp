#include <bits/stdc++.h>
using namespace std;

//이중우선순위큐
//https://school.programmers.co.kr/learn/courses/30/lessons/42628

int getNum(string s) {
    return 0;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> q;

    for(int i=0; i<operations.size(); i++) {
        if(operations[i][0]=='I') {
            int num = getNum(operations[i]);
            q.push_back(num);
        } else if(operations[i]=="D 1") {
            cout << "D 1" << '\n';
        } else if(operations[i]=="D -1") {
            cout << "D -1" << '\n';
        }
    }

    if(q.empty()) {answer.push_back(0); answer.push_back(0);}
    else {answer.push_back(*max_element(q.begin(),q.end())); answer.push_back(*min_element(answer.begin(),answer.end())); }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    vector<int> res = solution(operations);   
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    } 
}