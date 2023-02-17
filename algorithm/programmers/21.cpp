#include <bits/stdc++.h>
using namespace std;

//행렬의 곱셈
//https://school.programmers.co.kr/learn/courses/30/lessons/12949

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0; i<arr1.size(); i++) {
        vector<int> v;
        for(int j=0; j<arr2[0].size(); j++) {
            int tmp = 0;
            for(int k=0; k<arr1[i].size(); k++) {
                tmp += arr1[i][k] * arr2[k][j];
            }
            v.push_back(tmp);
        }
        answer.push_back(v);
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> arr1 = {{2, 3, 2}, {4, 2, 4}, {3, 1, 4}}; 
    vector<vector<int>> arr2 = {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}};
    vector<vector<int>> res = solution(arr1, arr2);
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}