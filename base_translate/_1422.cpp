/*
    将M进制的数X转换为N进制的数输出

    输入描述：
        输入的第一行包括两个整数：M和N(2<=M,N<=36)。
        下面的一行输入一个数X，X是M进制的数，现在要求你将M进制的数X转换成N进制的数输出。
    输出描述:
        输出X的N进制表示的数。

    tips:
        注意输入时如有字母，则字母为大写，输出时如有字母，则字母为小写。
*/

#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char** argv) {
    // m:输入的进制 n:输出的进制
    int m , n;
    // x:要转换的数据
    string x;
    cin >> m >> n;
    cin >>  x;
    // 先转换成10进制
    // temp:十进制的结果
    int temp = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] >= 'A' && x[i] <= 'Z')
        {
            temp = temp * m + (x[i] - 'A' + 10);
        }else
        {
            temp = temp * m + (x[i] - '0');
        }
    }
    if(n == 10) cout << temp;
    // 十进制转换成n进制
    char s[105];
    int cnt = 0;
    int rail = 0;
    while(temp > 0){
        rail = temp % n;
        if(rail < 10){
            s[cnt++] = (char(rail) + '0');
        }else
        {
            s[cnt++] = (char(rail - 10) + 'a');
        }
        temp /= n;
    }
    for (int i = cnt-1; i >= 0; i--)
    {
        cout << s[i];
    }
    
    return 0;
}