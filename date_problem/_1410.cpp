/*
    问题描述：
        给出年分m和一年中的第n天，算出第n天是几月几号。

    输入描述：
        输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)
    输出描述：
        可能有多组测试数据，对于每组数据，
        按 yyyy-mm-dd的格式将输入中对应的日期打印出来
    
    输入样例：
        2000 3
        2000 31
        2000 40
        2000 60
        2000 61
        2001 60
    输出样例：
        2000-01-03
        2000-01-31
        2000-02-09
        2000-02-29
        2000-03-01
        2001-03-01
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
    int year, days;
    while (cin >> year >> days)
    {
        //判断是否合法
        if (year < 1 || year > 3000 || days < 1 || days > 366)
        {
            cout << "INPUT ERROR" << endl;
        }
        // 判断是否闰年
        if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
        {
            f[2] = 29;
        }else
        {
            f[2] = 28;
        }
        
        p.year = year;
        int cnt = 1;
        while (days > f[cnt])
        {
            days -= f[cnt];
            cnt += 1;
        }
        p.month = cnt;
        p.day = days;

        //输出
        printf("%d-%02d-%02d\n", p.year, p.month, p.day);
    }

    return 0;
}
