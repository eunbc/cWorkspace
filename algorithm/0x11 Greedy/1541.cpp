#include <bits/stdc++.h>
using namespace std;

int main(void){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    string cal;
    cin >> cal;    
    istringstream ss(cal);
    string stringBuffer;
    vector<int> x;
    x.clear();    
    while (getline(ss, stringBuffer, '-')){
        istringstream gg(stringBuffer);
        string ggg;
        int num = 0;
        while(getline(gg, ggg, '+')) {
            num += stoi(ggg);                    
        }
        x.push_back(num);
    }

    int answer = x[0];
    for(int i=1; i<x.size(); i++) {
        answer -= x[i];
    }
    cout << answer;
    
}