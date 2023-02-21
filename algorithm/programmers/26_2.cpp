#include <bits/stdc++.h>
using namespace std;

//귤 고르기
//https://school.programmers.co.kr/learn/courses/30/lessons/138476

int arr[10000001];

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    //크기 별로 배열에 갯수를 저장
    for(int i=0; i<tangerine.size(); i++) {
        arr[tangerine[i]]++;
    }

    //갯수 목록 벡터에 저장, 내림차순 정렬
    vector<int> v;
    for(int i=0; i<10000001; i++) {
        if(arr[i]) v.push_back(arr[i]);
    }
    sort(v.rbegin(),v.rend());

    //k가 0이 될때까지 갯수 감소
    int cnt = 0,p=0;
    while(k>0) {
        k -= v[p++];
        cnt++;
    }
    answer = cnt;
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k = 2;
    vector<int> tangerine = {1, 1, 1, 1, 2, 2, 2, 3};
    cout << solution(k,tangerine);
}