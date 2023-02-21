#include <bits/stdc++.h>
using namespace std;

//기능개발
//https://school.programmers.co.kr/learn/courses/30/lessons/42586

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    //작업 별로 작업 일자를 구한다
    queue<int> q;
    for(int i=0; i<progresses.size(); i++) {
        int day = 0;
        while(progresses[i]<100) {
            progresses[i] += speeds[i];
            day++;
        }
        q.push(day);
    }

    while(!q.empty()) {
        int cnt = 1;
        int cur = q.front();
        q.pop();

        while(!q.empty() && cur >= q.front()) {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }

    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> progresses = {95, 90, 99, 99, 80, 99};
    vector<int> speeds = {1, 1, 1, 1, 1, 1};
    vector<int> res = solution(progresses, speeds);
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    }
}