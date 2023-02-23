#include <bits/stdc++.h>
using namespace std;

//이중우선순위큐
//https://school.programmers.co.kr/learn/courses/30/lessons/42628

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int> pq1; //내림차순
    priority_queue<int,vector<int>, greater<int>> pq2; //오름차순

    int cnt = 0;
    for(int i=0; i<operations.size(); i++) {
        //Insert
        if(operations[i][0]=='I') {
            int num = stoi(operations[i].substr(2));
            pq1.push(num);
            pq2.push(num);
            cnt++;        
        }

        //최소값 삭제
        else if(cnt!=0 && operations[i]=="D -1") {
            pq2.pop();
            cnt--;
        }

        //최대값 삭제
        else if(cnt!=0 && operations[i]=="D 1") {
            pq1.pop();
            cnt--;
        }

        if(cnt==0) {
            while(!pq1.empty()) pq1.pop();
            while(!pq2.empty()) pq2.pop();
        }

    }
    if(cnt) {
        answer[0] = pq1.top();
        answer[1] = pq2.top();
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> operations = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
    vector<int> res = solution(operations);   
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    } 
}