#include <bits/stdc++.h>
using namespace std;

//다음 큰 숫자
//https://school.programmers.co.kr/learn/courses/30/lessons/12911

string getBinary(int n) {
    string binary = "";
    while(n/2 > 0) {
        binary += to_string(n%2);
        n /= 2;
    }
    binary += to_string(n%2);
    reverse(binary.begin(), binary.end());
    return binary;
}

int countOne(string binary) {
    int cnt = 0;
    for(int i=0; i<binary.size(); i++) {
        if(binary[i]=='1') cnt++;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int original = n;
    string binary = getBinary(n);
    int one = countOne(binary);

    for(int i = original + 1; ;i++) {
        string binary2 = getBinary(i);
        int bigger = countOne(binary2);

        if(one==bigger) {
            answer = i;
            break;
        }
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 78;
    cout << solution(n);
}