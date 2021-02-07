/*
    问题描述：
        编写一个日期类，要求按xxxx-xx-xx 的格式输出日期，实现加一天的操作。

    输入描述：
        输入第一行表示测试用例的个数m，接下来m行每行有3个用空格隔开的整数，分别表示年月日。
        测试数据不会有闰年
    输出描述：
        输出m行。按xxxx-xx-xx的格式输出，表示输入日期的后一天的日期

    输入样例：
        2
        1999 10 20
        2001 1 31
    输出样例：
        1999-10-21
        2001-02-01

    tips:
       注意个位数日期前面要有0。 
*/

#include <bits/stdc++.h>

using namespace std;

int f[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
    int year;
    int month;
    int day;
} p;

int main(int argc, const char **argv)
{
    int m;
    cin >> m;
    while (m > 0)
    {
        cin >> p.year >> p.month >> p.day;
        //判断天数,加一
        if (p.day == f[p.month])
        {
            if (p.month == 12)
            {
                p.year++;
                p.month = 1;
            }
            else
            {
                p.month++;
            }
            p.day = 1;
        }
        else
        {
            p.day++;
        }
        //输出
        printf("%d-%02d-%02d\n", p.year, p.month, p.day);
        m--;
    }
    return 0;
}