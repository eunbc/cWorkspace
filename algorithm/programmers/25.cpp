#include <bits/stdc++.h>
using namespace std;

//기능개발
//https://school.programmers.co.kr/learn/courses/30/lessons/42586

int arr[101];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    //작업 별로 작업 일자를 구한다
    vector<int> days;
    for(int i=0; i<progresses.size(); i++) {
        int day = 0;
        while(progresses[i]<100) {
            progresses[i] += speeds[i];
            day++;
        }
        days.push_back(day);
    }

    if(days.size()==0) return answer;

    //배포 가능 일자를 구한다 
    int prv = days[0];
    for(int i=1; i<days.size(); i++) {
        if(days[i]<prv) days[i] = prv; 
        prv = days[i];
    }

    //배포 가능 일자 배열에 작업 갯수를 저장한다
    for(int i=0; i<days.size(); i++) {
        arr[days[i]]++;
    }

    //각각의 일자에 해당하는 작업 갯수 저장
    for(int i=0; i<101; i++) {
        if(arr[i]>0) answer.push_back(arr[i]);
    }

    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    vector<int> res = solution(progresses, speeds);
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << ' ';
    }
}