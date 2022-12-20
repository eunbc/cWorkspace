#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> Mytuple;

int main()
{
    Mytuple c0(1,2,3);
    int v4 = 4;
    int v5 = 5;
    int v6 = 6;

    c0 = make_tuple(v4,v5,v6);

    cout << get<0>(c0) << ' ';
    cout << get<1>(c0) << ' ';
    cout << get<2>(c0) << '\n';


    cout << "==================\n";

    
    c0 = tie(v4,v5,v6);

    cout << get<0>(c0) << ' ';
    cout << get<1>(c0) << ' ';
    cout << get<2>(c0) << ' ';

    return 0;
}

