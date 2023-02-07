#include <bits/stdc++.h>
using namespace std;

//구명보트(그리디)
//https://school.programmers.co.kr/learn/courses/30/lessons/42885

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(),greater<>());
    
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> people = {70, 80, 50,50};
    int limit = 100;
    cout << solution(people, limit);
}