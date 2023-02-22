#include <bits/stdc++.h>
using namespace std;

//프린터
//https://school.programmers.co.kr/learn/courses/30/lessons/42587?language=cpp

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    for(int i=0; i<priorities.size(); i++) {
        q.push({i, priorities[i]});
    }

    int mx = *max_element(priorities.begin(),priorities.end());
    while(true) {
        //큐 맨 앞 원소 꺼내서
        auto cur = q.front();
        
        //최대 우선순위가 아니면 뒤로 옮김
        if(q.front().second<mx) {
            q.pop(); q.push({cur.first,cur.second});
        } else {
            //최대 우선순위일 경우 꺼내고, 우선순위를 0으로 설정 
            q.pop();
            for(int i=0; i<priorities.size(); i++) {
                if(priorities[i]==cur.second) {
                    priorities[i] = 0;
                    break;
                }
            }      
            //최댓값 재설정
            mx = *max_element(priorities.begin(),priorities.end());
            answer++;
            if(cur.first==location) break;      
        }
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> priorities = {1,1,9,1,1,1};
    int location = 0;
    cout << solution(priorities, location);    
}