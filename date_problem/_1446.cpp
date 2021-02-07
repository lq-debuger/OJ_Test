/*
    问题描述：
        设计一个程序能计算一个日期加上若干天后是什么日期
    
    输入描述：
        输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
    输出描述：
        输出m行，每行按yyyy-mm-dd的个数输出。

    输入样例：
        1
        2008 2 3 100 
    输出样例：
        2008-05-13
*/

#include <bits/stdc++.h>

using namespace std;

int f[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};

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
        int days;
        cin >> p.year >> p.month >> p.day >> days;
        //判断是否是闰年
        if ((p.year % 400 == 0) || (p.year % 4 == 0) && (p.year % 100 != 0))
        {
            f[2] = 29;
        }
        else
        {
            f[2] = 28;
        }
        if (days <= f[p.month] - p.day)
        {
            p.day += days;
        }
        else
        {
            days = days - (f[p.month] - p.day);
            p.month++;
            while (days > f[p.month])
            {
                days -= f[p.month];
                if (p.month > 12)
                {
                    p.year++;
                    //这还需要判断是否是闰年
                    if ((p.year % 400 == 0) || (p.year % 4 == 0) && (p.year % 100 != 0))
                    {
                        f[2] = 29;
                    }
                    else
                    {
                        f[2] = 28;
                    }
                    p.month = 1;
                }
                else
                {
                    p.month++;
                }
            }
            p.day = days;
        }
        //输出
        printf("%d-%02d-%02d\n", p.year, p.month, p.day);
        m--;
    }
    return 0;
}