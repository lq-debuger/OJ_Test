#include<bits/stdc++.h>

using namespace std;

/*
    将一个长度最多为30位数字的十进制非负整数转换为二进制数输出
*/

// 去除字符串串首的零
void delete0(string &s){
    while (! s.empty() && s[0] == '0')
    {
        s.erase(s.begin());
    }
}

// 大数除法
string div_big_num(string s){
    string ans;
    // 前一个数除后的余数
    int plus = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int now = plus * 10 + (s[i] - '0');
        ans.push_back(char(now/2 + '0'));
        plus = now % 2;
    }
    delete0(ans);
    return ans;
}

int main(int argc, const char** argv) {
    string temp;
    while (cin >> temp)
    {
        string ans;
        delete0(temp);
        while (! temp.empty() && temp != "0")
        {
            // 余数
            int rail = (*(temp.end()-1) - '0') % 2;
            ans.push_back(char(rail + '0'));
            temp = div_big_num(temp);
        }
        reverse(ans.begin(),ans.end());
        if (! ans.empty())
        {
            cout << ans << endl;
        }else
        {
            printf("0\n");
        }
    }
    return 0;
}