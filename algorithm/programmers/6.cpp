#include <bits/stdc++.h>
using namespace std;

//이진 변환 반복하기
//https://school.programmers.co.kr/learn/courses/30/lessons/70129
int a,b;

void func(string s) {
    if(s=="1") return;
    //횟수 증가
    a++;

    //0 제거하기
    int zero = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='0') zero++;
    }
    b += zero;

    //이진수 만들기
    int num = s.size()-zero;
    string binary = "";
    while(num/2!=0) {
        binary += to_string(num % 2);
        num /= 2;
    }
    binary += to_string(num%2);
    reverse(binary.begin(),binary.end()); 

    //재귀
    func(binary);
}

vector<int> solution(string s) {
    vector<int> answer;
    func(s);
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "01110";
    vector<int> answer = solution(s);
    cout << answer[0] << ' ' << answer[1];
}