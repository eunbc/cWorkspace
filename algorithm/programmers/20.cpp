#include <bits/stdc++.h>
using namespace std;

//[1차] 캐시
//https://school.programmers.co.kr/learn/courses/30/lessons/17680

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> q;

    //대소문자 통일
    for(int i=0; i<cities.size(); i++) {
        for(int j=0; j<cities[i].size(); j++) cities[i][j] = toupper(cities[i][j]);        
    }
    
    for(int i=0; i<cities.size(); i++) {
        bool hit = false;
        int qNum = -1;
        //캐시에 존재하는지 확인
        for(int j=0; j<q.size(); j++) {
            if(cities[i]==q[j]) {
                answer += 1;
                hit = true;
                qNum = j;
                break;
            }
        }
        
        //cache hit
        if(hit && qNum>=0) {
            q.erase(q.begin()+qNum);
            q.push_back(cities[i]);
        }

        //cache miss
        if(!hit) {
            answer += 5;
            if(!q.empty() && q.size()>=cacheSize) q.pop_front();
            if(cacheSize > 0) q.push_back(cities[i]);        
        }
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cacheSize = 3;
    vector<string> cities = {"Jeju", "Jeju"};
    cout << solution(cacheSize, cities);

}