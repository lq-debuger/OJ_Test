#include<bits/stdc++.h>

using namespace std;

//10进制转换成x进制

int main(int argc, const char** argv) {
    int n , x ;
    char s[105] ; // 10进制以上又字符，所以用char存储
    // 输入10进制数 和要转换的进制x
    cin >> n >> x ;
    int cnt = 0 ; // 数组下标
    while (n > 0)
    {
        int w = (n % x);
        if(w < 10) s[cnt++] = w + '0' ; // 变成字符需要加'0'
        else s[cnt++] = (w - 10) + 'A' ; // 如果转换成小写加到'a'
        n /= x;
    }
    // 反序输出
    for (int i = cnt-1; i >= 0; i--)
    {
        printf("%c", s[i]);
    }
    

    
    return 0;
}
