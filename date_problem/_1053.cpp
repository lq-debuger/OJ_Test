/*
    问题描述：
        随着“开心农场”等娱乐游戏风靡互联网，“偷菜”遂瞬间蹿红网络，席卷网民生活。
        于是，“你‘偷’了吗”便成为大家见面的招呼语。很快，数百万都市白领成为“偷菜”队
        伍中的主力军，每天在“偷”与防“偷”中乐此不疲，甚至定闹钟半夜起床“偷”菜。根据
        “农作物”生长规律而变化制定偷菜时间表
    
    输入描述：
        假设当前时间为13：15，第一行输入作物种类数n,
        从第二行开始输入n 种作物成熟需要的时间，格式为
        Hour：Minute
    输出描述：
        依次输出n 种作物成熟时间，每行输出一个

    输入样例：
        3
        0:30
        1:10
        12:50
    输出样例：
        13:45
        14:25
        2:5
*/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char **argv)
{
    int n;
    cin >> n;
    while (n > 0)
    {
        string s;
        cin >> s;
        int cnt = 0, minute = 0,second = 0;
        while (s[cnt] != ':')
        {
            minute *= 10;
            minute += (s[cnt] - '0');
            cnt++;
        }
        cnt++;
        while (s[cnt] != '\0')
        {
            second *= 10;
            second += (s[cnt] - '0');
            cnt++;
        }
        minute += 13;
        second += 15;
        if (second >= 60)
        {
            int m = second / 60;
            second %= 60;
            minute += m;
        }
        minute %= 24;
        cout << minute << ":" << second << endl;
        n--;
    }
    return 0;
}
