#include <bits/stdc++.h>

using namespace std;

//设N是一个四位数，它的9倍恰好是其反序数（例如：1234的反序数是4321）求N的值

int main(int argc, const char **argv)
{
    //int n;
    //scanf("%d", &n);
    for (int i = 1000; i < 10000; i++)
    {   
        int ans = 0, num = i;
        if((num * 9) >= 10000) break;
        // 反序
        while (num > 0)
        {
            ans *= 10;
            ans += (num % 10);
            num /= 10;
        }
        if (ans == i * 9)
        {
            cout << i << endl;
        }
        // cout << endl;
    }

    
    return 0;
}