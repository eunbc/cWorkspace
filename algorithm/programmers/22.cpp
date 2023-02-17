#include <bits/stdc++.h>
using namespace std;

//위장
//https://school.programmers.co.kr/learn/courses/30/lessons/42578

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string,int> map; 
    for(int i=0; i<clothes.size(); i++) {
        if(map.find(clothes[i][1])!=map.end()) map[clothes[i][1]]++;
        else map[clothes[i][1]] = 1;
    }
    int tmp = 1;
    for(auto e : map) {
        tmp *= (e.second + 1);
    }
    answer = (tmp-1);
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes);    
}