#include <iostream>

using namespace std;

void splitStr(string &);
int main(){
    string str;
    while(getline(cin,str)){
        splitStr(str);

    }
}

void splitStr(string &str){
    long len = str.length();
    char c[9];
    c[8] = '\0';    // 设置字符串终结符
    long pos = 0;
    while(pos < len){
        c[pos & 0x7] = str[pos];
        pos++;
        if((pos & 0x7) == 0){ //　被８整除
            cout<<c<<endl;
        }
    }
    if(pos & 0x7){
        while(pos & 0x7){
            c[pos & 0x7] = '0';
            pos++;
        }
        cout<<c<<endl;
    }
}