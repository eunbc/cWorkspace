#include <bits/stdc++.h>
using namespace std;

//N개의 최소공배수
//https://school.programmers.co.kr/learn/courses/30/lessons/12953

int gcd(int a, int b)
{
    int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}

int lcm(int x, int y) { return x * y / gcd(x, y); }

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1; i<arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {2,6,8,14};
    cout << solution(arr);
}