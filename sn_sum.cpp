#include<bits/stdc++.h>

using namespace std;

// 2+22+222+2222....

int main(int argc, const char** argv) {
    int a , n ,sum = 0 ;
    cin >> a >> n ;
    int b = a ;
    for (int i = 0; i < n; i++)
    {
        sum += a;
        a = a * 10 + b ;
    }
    cout << sum << endl;
    return 0 ;
}
