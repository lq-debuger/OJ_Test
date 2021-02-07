/*
    问题描述：
        今天是2012年4月12日星期四，编写程序，输入今天开始到12月31日之间的任意日期，输出那一天是星期几。
        例如输入“5（回车）20（回车）”（5月20日），输出应为“Sunday”。

    输入描述：
        输入第一行为月份。
        输入第二行为这个月的第几天。
    输出描述：
        输入这一天是星期几。

    输入样例：
        5
        20
    输出样例：
        Sunday
    
*/

#include <bits/stdc++.h>

using namespace std;

int f[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string a[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main(int argc, const char **argv)
{
    // 输入
    int m, d;
    while (cin >> m >> d)
    {
        // 判断输入的是否合理
        if (m < 4 || m > 12 || d < 1 || d > f[m])
        {
            cout << "input error";
            continue;
        }
        // 计算
        int num = 0;
        if (m == 4)
        {
            num = d - 12;
        }else
        {   
            num += 18;
            for (int i = 5; i < m; i++)
            {
                num += f[i];
            }
            num += d;
        }
        int n = num % 7;
        int ans = (4 + n) % 7;
        // 输出
        cout << a[ans] << endl;
    }

    return 0;
}