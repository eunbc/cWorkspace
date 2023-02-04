#include <bits/stdc++.h>
using namespace std;

//카펫
//https://school.programmers.co.kr/learn/courses/30/lessons/42842

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> yaksu;
    int root = sqrt(yellow);
    for(int i=1; i <=root; i++) {
        if(yellow % i == 0) yaksu.push_back(i);
    }

    for(int i=0; i<yaksu.size(); i++) {
        int width = yellow / yaksu[i];
        int height = yaksu[i];
        if(brown == 2 * width + 2 * height + 4) {
            answer.push_back(width+2);
            answer.push_back(height+2);
            break;
        }
    }   
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int brown = 24;
    int yellow = 24;
    vector<int> answer = solution(brown,yellow);
    cout << answer[0] << ',' << answer[1];
}