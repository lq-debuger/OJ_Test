/*
    大家都知道，数据在计算机里中存储是以二进制的形式存储的。 有一天，小明学了C语言之后，他想知道一个类型为unsigned int 类型的数字，
    存储在计算机中的二进制串是什么样子的。 你能帮帮小明吗？并且，小明不想要二进制串中前面的没有意义的0串，即要去掉前导0。

    输入描述：
        每行有一个数字n（0<=n<=10^8），表示要求的二进制串。
    输出描述：
        输出共T行。每行输出求得的二进制串。

*/

#include<bits/stdc++.h>

using namespace std;

// 去除字符串前面的零
void delete0(string &s){
     while (! s.empty() && s[0] == '0')
     {
         s.erase(s.begin());
     } 
}

// 大数除法
string div_big_two(string s){
    string ans;
    // 前一个数除后的余数
    int plus = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int now = plus * 10 + (s[i] - '0');
        ans.push_back(char(now/2 + '0'));
        plus = now % 2 ;
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
            temp = div_big_two(temp);
        }
        reverse(ans.begin() , ans.end());
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