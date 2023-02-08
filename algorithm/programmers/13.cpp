#include <bits/stdc++.h>
using namespace std;

//구명보트(그리디)
//https://school.programmers.co.kr/learn/courses/30/lessons/42885

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    vector<bool> isused(people.size(), false);
    for(int i=0; i<people.size(); i++) {
        for(int j=people.size()-1; j>0; j--) {
            if(!isused[i] && !isused[j] && people[i] + people[j] <= limit) {
                isused[i] = true;
                isused[j] = true;
                answer++;    
            } 
        }
    }

    for(int i=0; i<isused.size(); i++) {
        if(!isused[i]) answer++;
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> people = {70, 80, 50};
    int limit = 100;
    cout << solution(people, limit);
}