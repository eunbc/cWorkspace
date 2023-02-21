#include <bits/stdc++.h>
using namespace std;

//귤 고르기
//https://school.programmers.co.kr/learn/courses/30/lessons/138476

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    //크기별 갯수 저장
    unordered_map<int,int> m;
    for(int i=0; i<tangerine.size(); i++) {
        m[tangerine[i]]++;        
    }

    //갯수 기준 정렬
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);

    queue<int> q;
    for(int i=0; i<v.size(); i++) {
        while(v[i].second>0) {
            q.push(v[i].first);
            v[i].second--;
        }
    }

    //정렬한 대로 큐에 넣고, k가 0이 될 때까지 다른 크기 갯수 증가
    int cur = 0;
    while(k>0) {
        if(q.front()!=cur) answer++;
        cur = q.front();
        q.pop();
        k--;
    }

    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k = 2;
    vector<int> tangerine = {1, 1, 1, 1, 2, 2, 2, 3};
    cout << solution(k,tangerine);
}