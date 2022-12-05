#include <bits/stdc++.h>
using namespace std;

int arr[1][8];

int main()
{
    string str;
    cin >> str;
    for (int j = 0; j < 8 ; j++) {
    //   arr[0][j] = str[j] - '0';
      arr[0][j] = str[j];
    }

    for (int i=0; i<8; i++) {
        cout << arr[0][i];
    }

}

