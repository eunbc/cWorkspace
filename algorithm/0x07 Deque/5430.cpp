#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& d){
  int cur = 0;
  for(int i = 1; i+1 < tmp.size(); i++)
  {
    if(tmp[i] == ','){
      d.push_back(cur);
      cur = 0;
    }
    else{
      cur = 10 * cur + (tmp[i] - '0');
    }
  }
  if(cur != 0)
    d.push_back(cur);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string query;
        int n;
        cin >> query;
        cin >> n;
        
        //입력받고 parsing 해서 덱에 넣기
        string tmp;
        cin >> tmp;
        deque<int> dq;
        parse(tmp,dq);

        bool isWrong = false;
        for(auto each : query) {
            if(each=='R') {
                reverse(dq.begin(),dq.end());
            } else if(each=='D') {
                if(dq.empty()) {
                    isWrong = true;
                    break;
                }
                else dq.pop_front();
            }
        }
        
        if(isWrong) {
            cout << "error" << '\n';
        } else {
            cout << '[';
            for(int i=0;i<dq.size(); i++) {
                cout << dq.at(i) ; 
                if(i+1!=dq.size()) cout << ',';
            }
            cout << ']' << '\n'; 
        }
    
    }
}