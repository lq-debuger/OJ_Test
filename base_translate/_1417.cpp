/*
    输入一个整数，将其转换成八进制数输出。

    输入包括一个整数N(0<=N<=100000)。
*/

#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    int n;
    int s[105];
    while (cin >> n)
    {
        int cnt = 0;
        while (n > 0)
        {
            s[cnt++] = n % 8;
            n /= 8;
        }
        for (int i = cnt -1; i >= 0; i--)
        {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}