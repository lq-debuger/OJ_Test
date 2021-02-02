#include<bits/stdc++.h>

using namespace std;

//x进制转换成y进制  x先转换成10进制 10进制转换成y进制


int main(int argc, const char** argv) {
    char s[105];
    int x, y;
    cin >> s >> x >> y;
    int ans  = 0;
    int len = strlen(s);
    //x进制转换成10进制
    for (int i = 0; i < len; i++)
    {
        ans *= x;
        if (s[i] >= '0' && s[i] <= '9')
        {
            ans += (s[i] - '0');
        }else
        {
            ans += (s[i] - 'A') + 10 ;
        }
    }
    //10进制转换成y进制
    char out[105];
    int cnt = 0;
    while (ans > 0)
    {   
        int w = ans % y;
        if (w < 10)
        {
            out[cnt++] = w + '0';
        }else
        {
            out[cnt++] = w - 10 + 'A';
        }
        ans /= y;
    }
    for (int i = cnt-1; i >= 0 ; i--)
    {
        cout << out[i] ;
    }
    
    cout << endl;
    return 0;
}