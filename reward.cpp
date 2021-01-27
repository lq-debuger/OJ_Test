#include<bits/stdc++.h>

using namespace std;

//求奖金

int main(int argc, const char** argv) {
    int profit , reward ;
    cin >> profit ;
    int m , l , n , o , p ;
    m = 100000 * 0.1 ;
    l = 100000 * 0.075;
    n = 200000 * 0.05;
    o = 200000 * 0.03;
    p = 400000 * 0.015;
    if (profit > 1000000)
    {
        reward = m + l + n + o + p + (profit - 1000000)*0.01;
    }else if (profit > 600000)
    {
        reward = m + l + n + o + (profit - 600000)*0.015;
    }else if (profit > 400000)
    {
        reward = m + l + n + (profit - 400000)*0.03;
    }else if (profit > 200000)
    {
        reward = m + l + (profit - 200000)*0.05;
    }else if (profit > 100000)
    {
        reward = m + (profit - 100000)*0.075;
    }else
    {
        reward = profit * 0.1 ;
    }
    cout << reward << endl ;
    
    return 0;
}
