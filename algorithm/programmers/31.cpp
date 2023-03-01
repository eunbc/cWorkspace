#include <bits/stdc++.h>
using namespace std;

//전화번호 목록
//https://school.programmers.co.kr/learn/courses/30/lessons/42577?language=cpp

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> map;
    for(int i=0; i<phone_book.size(); i++) {
        map[phone_book[i]]++;
    }

    for(int i=0; i<phone_book.size(); i++) {
        string phone_number = "";
        for(int j=0; j<phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(map[phone_number] && phone_number != phone_book[i])
                answer = false;
        }
        cout << '\n';
    }
    return answer;
}

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> phone_book = {"12","123","1235","567","88"};
    cout << solution(phone_book);
}