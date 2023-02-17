#include <bits/stdc++.h>
using namespace std;

//기능개발
//https://school.programmers.co.kr/learn/courses/30/lessons/42586

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0; i<10; i++) {
        
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1,30,5};
    vector<int> res = solution(progresses, speeds);
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    }
}