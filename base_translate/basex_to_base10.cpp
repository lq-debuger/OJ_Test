#include<bits/stdc++.h>

using namespace std;

//x进制转换成10进制

int main(int argc, const char** argv) {
    char s[105];
    int x;
    // 输入x进制的字符串 和 代表的进制x
    cin >> s >> x ;
    int ans = 0 ;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        ans = ans * x;
        if (s[i] >= '0' && s[i] <= '9')
            ans += (s[i] - '0');
        else ans += (s[i] - 'A') + 10;       
    }
    cout << ans << endl;

    return 0;
}