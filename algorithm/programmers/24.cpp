#include <bits/stdc++.h>
using namespace std;

//n^2 배열 자르기
//https://school.programmers.co.kr/learn/courses/30/lessons/87390


vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    //2차원 배열 생성(왜 큰 수를 넣으면 seg fault가 날까?)
    int arr[n][n];
    for(int i=0; i<n; i++) {
        fill(arr[i], arr[i]+n, 0);
    }

    for(long long i=1; i<=n; i++) {
        for(long long j=0; j<i; j++) {
            for(long long k=0; k<i; k++) {
                if(arr[j][k]==0) arr[j][k] = i;
            }
        }
    }

    //이어붙인 1차원 배열
    long long arr2[n*n];
    for(long long i=0; i<n; i++) {
        for(long long j=0; j<n; j++) {
            long long tmp = n*i + j;
            arr2[tmp] = arr[i][j];
        }
    }

    //left, right
    for(long long i=left; i<=right; i++) {
        answer.push_back(arr2[i]);
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 4;
    long long left = 7;
    long long right = 14;
    vector<int> res = solution(n,left, right);   
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    } 
}