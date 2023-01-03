#include <bits/stdc++.h>
using namespace std;


int main()
{
    int arr[10] = {3,2,7,116,62,235,1,23,55,77};
    int n = 10;
    for(int i=n-1; i>0; i--) {
        swap(*max_element(arr,arr+i+1), arr[i]);
    }
    
}

