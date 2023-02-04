#include <bits/stdc++.h>
using namespace std;

//영어 끝말잇기
//https://school.programmers.co.kr/learn/courses/30/lessons/12981

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int a=0,b=0,k=0x7f7f7f7f;
    for(int i=0; i<words.size(); i++) {
        for(int j=i+1; j<words.size(); j++) {
            if((j==i+1 && (words[i][words[i].length()-1]!=words[j][0])) 
            || words[i]==words[j]) {
                k = min(k,j);
            }    
        }
    }
    if(k!=0 || k!=0x7f7f7f7f) {
        a = k%n + 1;
        b = k/n + 1;
    }
    answer.push_back(a);
    answer.push_back(b); 
    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 2;
    vector<string> words = {"hello", "hello", "even", "never", "now", "world", "draw"};
    
    vector<int> answer = solution(n,words);
    cout << answer[0] << ',' << answer[1];
}