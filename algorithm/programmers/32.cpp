#include <bits/stdc++.h>
using namespace std;

//타겟 넘버
//https://school.programmers.co.kr/learn/courses/30/lessons/43165

int t,answer;
int arr[25];

void func(int k,vector<int> numbers,int max) {
    if(k==max) {
        int sum = 0;
        for(int i=0; i<max; i++) {
            sum += arr[i];
        }
        if(sum==t) answer++;
        return;
    }

    for(auto t : {1, -1}) {
        arr[k] = numbers[k] * t;
        func(k+1, numbers,max);
    }
}

int solution(vector<int> numbers, int target) {
    t = target;    
    func(0,numbers,numbers.size());
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> numbers = {4,1,2,1};
    int target = 4;
    cout << solution(numbers,target);    
}