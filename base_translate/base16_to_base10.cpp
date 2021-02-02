#include<bits/stdc++.h>

using namespace std;

//写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串(注意可能存在的一个测试用例里的多组数据)。


int main(int argc, const char** argv) {
    char s[105];
    scanf("%s",s);
    int len = strlen(s);
    int ans = 0;
    for (int i = 2; i < len; i++)
    {   
        ans *= 16;
        if (s[i] <= '9' && s[i] >= '0')
        {
            ans += (s[i] - '0');
        }else
        {
            ans += (s[i] - 'A') + 10;
        }
    }
    cout << ans << endl;
    return 0;
}