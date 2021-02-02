#include<iostream>

using namespace std;

//输出二进制序列

void to_binary(int a){
    int binary[6]{0,0,0,0,0,0};
    int count = 5;
    while (a)
    {
        binary[count] = a%2;
        a /= 2;
        count--;
    }
    for (int i = 0; i < 6; i++)
    {
        cout << binary[i];
    }      
}

int main(int argc, const char** argv) {
    for (int i = 0; i < 64; i++) {
        to_binary(i);
        cout << endl;
    }
    
    return 0;
}
