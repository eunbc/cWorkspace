#include <bits/stdc++.h>
using namespace std;

//다음 큰 숫자
//https://school.programmers.co.kr/learn/courses/30/lessons/12911

int solution(int n) {
    int answer = 0;

    //n 이진수 변환
    string binary = "";
    int num = 0;
    while(n/2!=0) {
        binary += to_string(n%2);
        if(n%2==1) num++;
        n /= 2;
    }
    binary += to_string(n%2);
    num++;
    reverse(binary.begin(),binary.end());
    cout << binary << '\n';


    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 15;
    cout << solution(n);
}