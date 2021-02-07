/*
    问题描述：
        有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
    
    输入描述：
        有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
    输出描述：
        每组数据输出一行，即日期差值

    输入样例：
        20110412
        20110422
    输出样例：
        11
*/

#include <bits/stdc++.h>

using namespace std;

int f1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int f2[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
    int year;
    int month;
    int day;
};

// 从字符串提取年
int extract_year(string s)
{
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {
        temp *= 10;
        temp += (s[i] - '0');
    }
    return temp;
}

// 从字符串提取月
int extract_month(string s)
{
    int temp = 0;
    for (int i = 4; i < 6; i++)
    {
        temp *= 10;
        temp += (s[i] - '0');
    }
    return temp;
}

// 从字符串提取日
int extract_day(string s)
{
    int temp = 0;
    for (int i = 6; i < 8; i++)
    {
        temp *= 10;
        temp += (s[i] - '0');
    }
    return temp;
}

int main(int argc, const char **argv)
{
    Date p1, p2;
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        p1.year = extract_year(s1);
        p2.year = extract_year(s2);
        p1.month = extract_month(s1);
        p2.month = extract_month(s2);
        p1.day = extract_day(s1);
        p2.day = extract_day(s2);
        // 判断输入是否合法
        int cnt = 0;
        if (p1.month < 0 || p1.month > 12 || p1.day < 0 || p1.day > f1[p1.month])
            cnt = 1;
        if (p2.month < 0 || p2.month > 12 || p2.day < 0 || p2.day > f2[p1.month])
            cnt = 1;
        if (cnt == 1)
            cout << "input error" << endl;
        // 判断是不是闰年
        if ((p1.year % 400 == 0) || (p1.year % 4 == 0) && (p1.year % 100 != 0))
        {
            f1[2] = 29;
        }
        if ((p2.year % 400 == 0) || (p2.year % 4 == 0) && (p2.year % 100 != 0))
        {
            f2[2] = 29;
        }
        // 计算天数差
        int num = 0;
        int year = p2.year - p1.year;
        int month = p2.month - p1.month;
        int day = p2.day - p1.day;
        if (year == 0)
        {
            if (month == 0)
            {
                num = day + 1;
            }
            else
            {
                for (int i = p1.month + 1; i < p2.month; i++)
                {
                    num += f2[p2.month];
                }
                num = num + f1[p1.month] - p1.day + 1 + p2.day;
            }
        }else
        {
            
        }
        cout << num << endl;
        
    }
    return 0;
}