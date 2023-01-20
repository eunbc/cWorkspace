#include <bits/stdc++.h>
using namespace std;

//정수 삼각형
// https://school.programmers.co.kr/learn/courses/30/lessons/43105
int d[505][505];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    d[1][1] = triangle[0][0];
    for(int i=2; i<=triangle.size(); i++) {
        for(int j=1; j<=triangle[i-1].size(); j++) {
            d[i][j] = max(d[i-1][j], d[i-1][j-1])+triangle[i-1][j-1];
        }
    }
    answer = *max_element(d[triangle.size()] + 1, d[triangle.size()] + triangle.size() + 1);
    
    for(int i=1; i<=triangle.size(); i++) {
        for(int j=1; j<=triangle.size(); j++) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> v = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    cout << solution(v);
}