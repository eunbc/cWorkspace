#include <bits/stdc++.h>
using namespace std;

//점프와 순간 이동
//https://school.programmers.co.kr/learn/courses/30/lessons/12980

int solution(int n)
{
    int ans = 0;
    while(n>0) {
        if(n%2==0) n/=2;
        else {
            n -= 1;
            ans++;
        } 
    }
    return ans;

}
    // while(n>0) {
    //     ans += n%2;
    //     n /= 2;
    // }
    // return ans;
int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 5000;
    cout << solution(n);
}